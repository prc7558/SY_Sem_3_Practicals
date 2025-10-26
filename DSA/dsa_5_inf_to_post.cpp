#include<iostream>
using namespace std;

class stack {
private:
    char arr[50]; int top;
    
public:
    string exp;
    
    stack() { top = -1; }

    void push(char ch) {
        arr[++top] = ch;
    }

    char pop() {
        if (top == -1) return 0;
        return arr[top--];
    }

    char peek() {
        if (top == -1) return 0;
        return arr[top];
    }

    bool isEmpty() {
        return top==-1;
    }

    int precedence(char op) {
        if (op=='+' || op=='-') return 1;
        if (op=='*' || op=='/') return 2;
        if (op=='^') return 3;
        return 0;
    }

    string infixToPostfix();
};

string stack::infixToPostfix() {
    string postfix = "";
    
    for (char ch : exp) {
        if ((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z') || (ch>='0'&&ch<='9'))
            postfix += ch;
            
        else if (ch=='(') push(ch);
            
        else if (ch == ')') {
            while (!isEmpty() && peek()!='(') postfix+=pop();
            pop();
        }
        else {
            while (!isEmpty() && precedence(peek()) >= precedence(ch))
                postfix += pop();
            push(ch);
        }
    }
    while (!isEmpty()) postfix += pop();
    return postfix;
}

int evaluate(string post) {
    int a, b, arr[50], numTop=-1;
    for(char ch : post) {
        if(isdigit(ch)) arr[++numTop] = ch-'0';
        else {
            b=arr[numTop--]; a=arr[numTop--];
            switch(ch) {
                case '+': arr[++numTop]=a+b; break;
                case '-': arr[++numTop]=a-b; break;
                case '*': arr[++numTop]=a*b; break;
                case '/': arr[++numTop]=a/b; break;
            }
        }
    } return arr[numTop];
}

int main() {
    stack s; int result; string postfix;
    
    cout << "Enter Infix Expression: ";
    cin >> s.exp;

    postfix = s.infixToPostfix();
    cout << "Postfix Expression: " << postfix << endl;
    
    result = evaluate(postfix);
    cout << "Answer is: " << result << endl;

    return 0;
}
/*Algorithm: Infix to Postfix Conversion
1. Initialize an empty stack S and an empty string postfix.
2. Read the infix expression from left to right, character by character.
3. For each character ch in the expression:
	a. If ch is an operand (letter or digit), append it to postfix.
	b. If ch is '(', push it onto the stack.
	c. If ch is ')',
		i. Pop and append characters from the stack to postfix until '(' is found.
		ii. Pop the '(' from the stack but do not append it.
	d. If ch is an operator (+, -, *, /, ^):
		i. While the stack is not empty and the operator at the top of the stack has
			higher or equal precedence than ch, pop from the stack and append to postfix.
		ii. Push ch onto the stack.
4. After reading the expression, pop any remaining operators
	from the stack and append them to postfix.
5. Output the postfix string.*/
