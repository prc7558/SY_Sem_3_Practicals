/*Step 1: Detect the loop using two pointers (slow and fast)
Step 2: If loop exists, find the starting node of the loop
Step 3: Remove the loop by making the last node’s next = NULL*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* newNode(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;
    return temp;
}

// Function to detect and remove loop
void detectAndRemoveLoop(Node* head) {
    Node *slow = head, *fast = head;

    // Step 1: Detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;  // Loop detected
    }

    // If no loop found
    if (fast == NULL || fast->next == NULL) {
        cout << "No Loop detected.\n";
        return;
    }

    // Step 2: Move slow to head
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    // Step 3: Remove loop
    fast->next = NULL;
    cout << "Loop removed successfully.\n";
}

// Function to print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Creating a loop for testing
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head); // Detect & remove loop

    cout << "Linked List after loop removal: ";
    printList(head);
    return 0;
}