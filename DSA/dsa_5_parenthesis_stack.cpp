#include<iostream>
using namespace std;

class stack {
private:
	char arr[10]; int top;
	
public:
	string exp;
	
	stack() { top=-1; }
	
	void push(char ch) {
		arr[++top] = ch;
	}
	
	char pop() {
		if (top==-1) return 0;
		return arr[top--];
	}
	
	bool isEmpty() {
		return top==-1;
	}
	
	bool isBalanced(string expr);
	
	/*char peek() {
		  if (top==-1) return 0;
      return arr[top];
	}*/
};

bool stack::isBalanced(string expr) {
    for (char ch : expr) {
        if (ch=='(' || ch=='{' || ch=='[')
            push(ch);
        else if (ch==')' || ch=='}' || ch==']') {
            if (isEmpty()) return false;
            char top = pop();
            if ((ch==')' && top!='(') ||
                (ch=='}' && top!='{') ||
                (ch==']' && top!='['))
                return false;
        }
    } return isEmpty();
}

int main() {
	stack s;
	cout << "Enter Expression: ";
	cin >> s.exp; cout << endl;
	
	if (s.isBalanced(s.exp)) cout << "Well parenthesized." << endl;
    else cout << "Not Well parenthesized." << endl;
	
	return 0;
}
