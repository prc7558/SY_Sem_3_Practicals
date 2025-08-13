#include<iostream>
using namespace std;

class node {
	public:
		int data;
		node *next;
} *head, *newnode;

int main() {
	head = NULL;
	newnode = new node();
	
	cin >> newnode -> data;
	newnode -> next=NULL;
	head = newnode;
	
	cout << head -> data;
	cout << newnode -> data;
	
	return 0;
}