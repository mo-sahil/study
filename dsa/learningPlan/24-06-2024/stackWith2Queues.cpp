#include <iostream>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> q1, q2;

public:
    void push(int value) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(value);

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << std::endl;
            return;
        }

        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << std::endl;
            return -1;
        }

        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.top() << endl;

    stack.pop();
    stack.pop();

    cout << "Top element: " << stack.top() << endl;

    return 0;
}