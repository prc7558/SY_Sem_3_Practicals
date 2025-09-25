#include<iostream>
#include<string>
using namespace std;

//~~~GLOBAL VARIABLES~~~
int front=-1, rear=-1, i, n;
string *jobs;

//~~~FUNCTION DECLARATIONS~~~
void enqueue();
void dequeue();
void display();

int main() {
    cout << "Enter maximum number of print jobs in spooler: ";
    cin >> n; int ch;
    jobs = new string[n];
    
    cout << "\n--- Printer Spooler Menu ---\n";
    
    do {
        cout << "\n1. Add Print Job";
        cout << "\n2. Process Print Job";
        cout << "\n3. Show All Print Jobs";
        cout << "\n4. Exit\n";
        cout << "\nChoose an option: ";
        cin >> ch;

        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: cout << "\nExiting Printer Spooler...\n"; break;
            default: cout << "\nInvalid option! Try again.\n";
        }
        
    } while (ch!=4);

    delete[] jobs;
    return 0;
}


//~~~ADD JOB TO CIRCULAR QUEUE~~~
void enqueue() {
    if ((front==0 && rear==n-1) || (rear+1)%n==front)
        cout << "\nSpooler is full! Cannot add more print jobs.\n";
    else {
        string name;
        cout << "Enter print job name: ";
        cin.ignore();
        getline(cin, name);
        
        if (front==-1) {
            front=0; rear=0;
        } else rear=(rear+1)%n;
        
        jobs[rear]=name;
        cout << "\n Print job \"" << name << "\" added to the spooler.\n";
    }
}

//~~~PROCESS JOB IN CIRCULAR QUEUE~~~
void dequeue() {
    if (front==-1) cout << "\nNo print jobs to process!\n";
    else {
        cout << "\n Processing print job: \"" << jobs[front] << "\"\n";
        jobs[front]="";
                
        if (front==rear) {
            front=-1; rear=-1;
        } else front=(front+1)%n;
    }
}

//~~~SHOW ALL JOBS IN CIRCULAR QUEUE~~~
void display() {
    if (front==-1) cout << "\nNo print jobs in the queue.\n";
    else {
        cout << "\nCurrent Print Queue: ";
        for (i=front; i!=rear; i=(i+1)%n) 
            cout << "\"" << jobs[i] << "\"" << " -> ";
        cout << "\"" << jobs[rear] << "\"\n";
    }
}
