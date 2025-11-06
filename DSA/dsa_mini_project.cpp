#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

const int TOTAL_FLOORS = 20;
const int NUM_ELEVATORS = 4;
const int ANIMATION_DELAY_MS = 1100;
// Enum for elevator direction
enum Direction {
    UP, DOWN, IDLE
};

template <typename T>
class Node {
public:
    T data;
    Node* next;
    
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class CustomQueue {
private:
    Node<T>* frontNode;
    Node<T>* rearNode;
    int count;
    
public:
    CustomQueue() : frontNode(nullptr), rearNode(nullptr), count(0) {}
    
    ~CustomQueue() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    // Push element to queue
    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
    }
    
    // Pop element from queue
    void pop() {
        if (isEmpty()) return;
        
        Node<T>* temp = frontNode;
        frontNode = frontNode->next;
        
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
        
        delete temp;
        count--;
    }
    
    // Get front element
    T front() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty!");
        }
        return frontNode->data;
    }
    
    // Check if empty
    bool isEmpty() {
        return frontNode == nullptr;
    }
    
    // Get size
    int size() {
        return count;
    }
    
    // Display all elements (for debugging)
    void display() {
        Node<T>* temp = frontNode;
        cout << "[ ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "]";
    }
};

// Structure for passenger request
struct Request {
    int floor;
    Direction direction;
    time_t timestamp;
    
    Request(int f, Direction d) : floor(f), direction(d) {
        timestamp = time(nullptr);
    }
};

// Forward declaration
class ElevatorSystem;

// Structure for elevator
struct Elevator {
    int id;
    int currentFloor;
    Direction currentDirection;
    bool isMoving;
    CustomQueue<int> destinationQueue;
    int totalDistance;
    
    Elevator(int i) : id(i), currentFloor(1), currentDirection(IDLE), 
                     isMoving(false), totalDistance(0) {}
    
    // Calculate distance to a floor
    int distanceTo(int floor) {
        return abs(currentFloor - floor);
    }
    
    // Calculate priority score for selection (lower is better)
    int getPriorityScore(int targetFloor) {
        int distance = distanceTo(targetFloor);
        int penalty = 0;
        
        // Prefer IDLE elevators
        if (currentDirection == IDLE) {
            penalty = 0;
        } else {
            penalty = 2;  // Small penalty for busy elevators
        }
        
        // Add queue size as penalty
        penalty += destinationQueue.size();
        // Distance is most important
        return distance * 10 + penalty;
    }
    
    // Move elevator one floor
    void move() {
        if (destinationQueue.isEmpty()) {
            isMoving = false;
            currentDirection = IDLE;
            return;
        }
        
        int target = destinationQueue.front();
        
        if (currentFloor < target) {
            currentFloor++;
            currentDirection = UP;
            totalDistance++;
        } else if (currentFloor > target) {
            currentFloor--;
            currentDirection = DOWN;
            totalDistance++;
        }
        
        if (currentFloor == target) {
            cout << "   [!] Elevator " << id << " arrived at floor " << currentFloor << endl;
            destinationQueue.pop();
            if (destinationQueue.isEmpty()) {
                isMoving = false;
                currentDirection = IDLE;
            }
        }
        isMoving = true;
    }
    
    // Add destination to queue
    void addDestination(int floor) {
        destinationQueue.push(floor);
        isMoving = true;
    }
    
    // Display elevator status
    void displayStatus() {
        cout << "   Elevator " << id << " - Floor: " << setw(2) << currentFloor 
             << " | Direction: ";
        if (currentDirection == UP) cout << "UP  ";
        else if (currentDirection == DOWN) cout << "DOWN";
        else cout << "IDLE";
        cout << " | Queue: " << destinationQueue.size()
             << " | Distance: " << totalDistance << " floors" << endl;
    }
};

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void sleepMs(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

// Draw visual representation of elevator shaft
void drawElevatorShaft(vector<Elevator*>& elevators) {
    clearScreen();
    
    cout << "\n+======================================================+" << endl;
    cout << "|     SMART MULTI-ELEVATOR SCHEDULING SYSTEM          |" << endl;
    cout << "+======================================================+" << endl;
    cout << "\n";
    cout << "    +";
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        cout << "--------+";
    }
    cout << "\n";	    
    
    // Draw floors from top to bottom
    for (int floor = TOTAL_FLOORS; floor >= 1; floor--) {
        cout << " " << setw(2) << floor << " |";
        
        // Draw each elevator
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            Elevator* elev = elevators[i];
            
            if (elev->currentFloor == floor) {
                // Show elevator
                if (elev->currentDirection == UP) {
                    cout << " [^" << elev->id << "^] ";
                } else if (elev->currentDirection == DOWN) {
                    cout << " [v" << elev->id << "v] ";
                } else {
                    cout << " [=" << elev->id << "=] ";
                }
            } else {
                cout << "   ||  ";
            }
            cout << " |";
        }
        cout << endl;
    }
    
    // Draw ground
    cout << "    +";
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        cout << "--------+";
    }
    cout << "\n     ";
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        cout << "   E" << (i+1) << "    ";
    }
    cout << "\n\n";
    
    // Display elevator status
    cout << "+------------------------------------------------------+" << endl;
    cout << "| ELEVATOR STATUS                                      |" << endl;
    cout << "+------------------------------------------------------+" << endl;
    for (Elevator* elev : elevators) {
        elev->displayStatus();
    }
    cout << "+------------------------------------------------------+" << endl;
}

class ElevatorSystem {
private:
    vector<Elevator*> elevators;
    CustomQueue<Request> pendingRequests;
    int totalRequests;
    
    // Implements SSTF algorithm manually
    Elevator* findNearestElevator(int floor, Direction dir) {
        if (elevators.empty()) return nullptr;
        
        Elevator* bestElevator = elevators[0];
        int bestScore = bestElevator->getPriorityScore(floor);
        
        // Linear search for best elevator
        for (size_t i = 1; i < elevators.size(); i++) {
            int currentScore = elevators[i]->getPriorityScore(floor);
            
            if (currentScore < bestScore) {
                bestScore = currentScore;
                bestElevator = elevators[i];
            }
        }
        
        return bestElevator;
    }
    
public:
    ElevatorSystem() : totalRequests(0) {
        int startFloors[] = {0, 2, 8, 16};
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            Elevator* elev = new Elevator(i + 1);
            elev->currentFloor = startFloors[i];
            elevators.push_back(elev);
        }
    }
    
    ~ElevatorSystem() {
        for (Elevator* elev : elevators) {
            delete elev;
        }
    }
    
    // Request elevator
    void requestElevator(int floor, Direction direction) {
        if (floor < 0 || floor > TOTAL_FLOORS) {
            cout << "   [ERROR] Invalid floor number!" << endl;
            return;
        }
        
        cout << "\n>>> NEW REQUEST <<<" << endl;
        cout << "   Floor " << floor << " | Direction: " 
             << (direction == UP ? "UP" : "DOWN") << endl;
        
        Request req(floor, direction);
        totalRequests++;
        
        // Use manual priority selection (no priority_queue)
        Elevator* selected = findNearestElevator(floor, direction);
        
        cout << "   >> Assigned Elevator " << selected->id 
             << " (Distance: " << selected->distanceTo(floor) << " floors)" << endl;
        
        selected->addDestination(floor);
    }
    
    // Add destination floor
    void addDestination(int elevatorId, int destinationFloor) {
        if (elevatorId < 0 || elevatorId > NUM_ELEVATORS) {
            cout << "   [ERROR] Invalid elevator ID!" << endl;
            return;
        }
        
        if (destinationFloor < 1 || destinationFloor > TOTAL_FLOORS) {
            cout << "   [ERROR] Invalid floor number!" << endl;
            return;
        }
        
        elevators[elevatorId - 1]->addDestination(destinationFloor);
        cout << "   Destination floor " << destinationFloor 
             << " added to Elevator " << elevatorId << endl;
    }
    
    // Simulate one time step
    void step() {
        for (Elevator* elev : elevators) {
            if (elev->isMoving) {
                elev->move();
            }
        }
    }
    
    // Display system status (non-animated)
    void displayStatus() {
        cout << "\n+======================================================+" << endl;
        cout << "| ELEVATOR SYSTEM STATUS                               |" << endl;
        cout << "+======================================================+" << endl;
        for (Elevator* elev : elevators) {
            elev->displayStatus();
        }
        cout << "+======================================================+" << endl;
    }
    
    // Display statistics
    void displayStatistics() {
        int totalDistance = 0;
        cout << "\n+======================================================+" << endl;
        cout << "| SYSTEM STATISTICS                                    |" << endl;
        cout << "+======================================================+" << endl;
        cout << "   Total Requests Processed: " << totalRequests << endl;
        
        for (Elevator* elev : elevators) {
            cout << "   Elevator " << elev->id << " - Total Distance: " 
                 << elev->totalDistance << " floors" << endl;
            totalDistance += elev->totalDistance;
        }
        
        cout << "   Combined Distance: " << totalDistance << " floors" << endl;
        if (totalRequests > 0) {
            cout << "   Average Distance per Request: " 
                 << fixed << setprecision(2) 
                 << (double)totalDistance / totalRequests << " floors" << endl;
        }
        cout << "+======================================================+" << endl;
    }
    
    // Check if any elevator is moving
    bool isAnyElevatorMoving() {
        for (Elevator* elev : elevators) {
            if (elev->isMoving) return true;
        }
        return false;
    }
    
    // Get elevators vector for animation
    vector<Elevator*>& getElevators() {
        return elevators;
    }
    
    // Animated simulation step
    void animatedStep() {
        step();
        drawElevatorShaft(elevators);
        sleepMs(ANIMATION_DELAY_MS);
    }
};

void displayMenu() {
    cout << "\n+======================================================+" << endl;
    cout << "|      SMART MULTI-ELEVATOR SCHEDULING SYSTEM          |" << endl;
    cout << "+======================================================+" << endl;
    cout << "|   1. Request Elevator (UP)                           |" << endl;
    cout << "|   2. Request Elevator (DOWN)                         |" << endl;
    cout << "|   3. Add Destination Floor                           |" << endl;
    cout << "|   4. Display System Status                           |" << endl;
    cout << "|   5. Run Single Step                                 |" << endl;
    cout << "|   6. Run Animated Simulation                         |" << endl;
    cout << "|   7. Run Demo with Animation                         |" << endl;
    cout << "|   8. Display Statistics                              |" << endl;
    cout << "|   9. Exit                                            |" << endl;
    cout << "+======================================================+" << endl;
    cout << "Enter your choice: ";
}

void runAnimatedDemo(ElevatorSystem& system) {
    clearScreen();
    cout << "\n\n*** STARTING ANIMATED DEMO SIMULATION ***\n" << endl;
    cout << "Generating random elevator requests...\n" << endl;
    sleepMs(1000);
    
    // Generate demo requests
    system.requestElevator(7, UP);
    sleepMs(500);
    system.addDestination(1, 12);
    sleepMs(500);
    
    system.requestElevator(3, DOWN);
    sleepMs(500);
    system.addDestination(2, 1);
    sleepMs(500);
    
    system.requestElevator(15, DOWN);
    sleepMs(500);
    system.addDestination(4, 8);
    sleepMs(500);
    
    system.requestElevator(18, UP);
    sleepMs(500);
    system.addDestination(3, 20);
    sleepMs(500);
    
    cout << "\n*** ANIMATION STARTING ***" << endl;
    cout << "Press Ctrl+C to stop...\n" << endl;
    sleepMs(2000);
    
    // Run animated simulation
    int steps = 0;
    auto startTime = chrono::high_resolution_clock::now();
    
    while (system.isAnyElevatorMoving() && steps < 100) {
        steps++;
        system.animatedStep();
    }
    
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(endTime - startTime);
    
    cout << "\n*** SIMULATION COMPLETE ***" << endl;
    cout << "Total Steps: " << steps << endl;
    cout << "Total Time: " << duration.count() << " seconds" << endl;
    
    system.displayStatistics();
    
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

int main() {
    ElevatorSystem system;
    int choice, floor, elevatorId;
    
    cout << "\n+======================================================+" << endl;
    cout << "|   Welcome to Smart Multi-Elevator Scheduling System! |" << endl;
    cout << "|   Building: " << TOTAL_FLOORS << " Floors | Elevators: " << NUM_ELEVATORS << "                 |" << endl;
    cout << "+======================================================+" << endl;
    
    sleepMs(1000);
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\n   [ERROR] Invalid input! Please enter a number." << endl;
            sleepMs(1000);
            continue;
        }
        
        switch (choice) {
            case 1:  // Request UP
                cout << "   Enter floor number (0-" << TOTAL_FLOORS-1 << "): ";
                cin >> floor;
                system.requestElevator(floor, UP);
                sleepMs(500);
                break;
                
            case 2:  // Request DOWN
                cout << "   Enter floor number (1-" << TOTAL_FLOORS << "): ";
                cin >> floor;
                system.requestElevator(floor, DOWN);
                sleepMs(500);
                break;
                
            case 3:  // Add destination
                cout << "   Enter elevator ID (1-" << NUM_ELEVATORS << "): ";
                cin >> elevatorId;
                cout << "   Enter destination floor (0-" << TOTAL_FLOORS << "): ";
                cin >> floor;
                system.addDestination(elevatorId, floor);
                sleepMs(500);
                break;
                
            case 4:  // Display status
                system.displayStatus();
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
                
            case 5:  // Single step
                system.step();
                system.displayStatus();
                sleepMs(500);
                break;
                
            case 6:  // Animated step
                drawElevatorShaft(system.getElevators());
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
                
            case 7:  // Animated demo
                runAnimatedDemo(system);
                break;
                
            case 8:  // Statistics
                system.displayStatistics();
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
                
            case 9:  // Exit
                clearScreen();
                cout << "\n   Thank you for using the Elevator System!" << endl;
                system.displayStatistics();
                return 0;
                
            default:
                cout << "\n   [ERROR] Invalid choice! Please try again." << endl;
                sleepMs(1000);
        }
    }
    
    return 0;
}
