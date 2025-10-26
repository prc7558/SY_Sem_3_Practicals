#include <iostream>
using namespace std;
#define MAX 100

class MinStack {
private:
    int stack[MAX], minStack[MAX];
    int topIndex, minTop;

public:
    MinStack() {
        topIndex = -1;
        minTop = -1;
    }

    void push(int x) {
        if (topIndex >= MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        stack[++topIndex] = x;

        if (minTop == -1 || x <= minStack[minTop])
            minStack[++minTop] = x;
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        int removed = stack[topIndex--];

        if (removed == minStack[minTop])
            minTop--;
    }

    int top() {
        if (topIndex == -1) {
            cout << "Stack Empty\n";
            return -1;
        }
        return stack[topIndex];
    }

    int getMin() {
        if (minTop == -1) {
            cout << "Stack Empty\n";
            return -1;
        }
        return minStack[minTop];
    }
};

int main() {
    MinStack s;
    s.push(5);
    s.push(2);
    s.push(8);
    s.push(1);
    cout << "Current Min: " << s.getMin() << endl; // 1
    s.pop();
    cout << "Current Min after one pop: " << s.getMin() << endl; // 2
    return 0;
}