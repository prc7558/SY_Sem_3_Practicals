#include<iostream>
#include<string>
using namespace std;

int main() {

    int i, ch, front=-1, rear=-1;
    const int n=5;
    string coffee[n];

    //~~~INITIALISE QUEUE~~~
    for (i=0; i<n; i++) coffee[i] = "";

    //~~~WELCOME MESSAGE~~~
    cout << "Welcome to MMCOE Wild Bean Cafe \n";
    cout << "Coffee Ordering Queue \n";
    cout << "\n--- Coffee Shop Queue Menu ---";
    
    //~~~LOOP until USERS EXIT~~~
    do {
        cout << "\n1. New Customer Arrival (Enqueue)";
        cout << "\n2. Serve Customer (Dequeue)";
        cout << "\n3. Show Queue";
        cout << "\n4. Exit\n";
        cout << "\nChoose an option: ";
        cin >> ch;

        //~~~ENQUEUE~~~
        if (ch==1) {
            if (rear==n-1) cout << "Queue is full! \n";
            else {
                string name;
                cout << "Enter customer name: ";
                cin >> name;
                if (front==-1 && rear==-1) {
                    front=0; rear=0;
                } else rear++;
                coffee[rear]=name;
                cout << "\n" << name << " joined the line.\n";
            }
        }

        //~~~DEQUEUE~~~
        else if (ch==2) {
            if (front==-1) cout << "\nQueue is empty! \n";
            else {
                cout << "\n" << coffee[front] << "'s order is ready. They leave the line.\n";
                for (i=front; i<rear; i++) coffee[i]=coffee[i+1];
                coffee[rear]=""; rear--;
                if (rear<0) {
                    front=-1; rear=-1;
                }
            }
        }

        //~~~DISPLAY QUEUE~~~
        else if (ch==3) {
            if (front==-1) cout << "\nLine is empty.\n";
            else {
                cout << "\nCurrent Line: ";
                for (i=front; i<=rear; i++) {
                    cout << coffee[i];
                    if (i<rear) cout << " -> ";
                } cout << endl;
            }
        }
    } while (ch != 4);
    
    //~~~EXIT MESSAGE~~~
    cout << "\nThank You for visiting! \n";
    return 0;
}
