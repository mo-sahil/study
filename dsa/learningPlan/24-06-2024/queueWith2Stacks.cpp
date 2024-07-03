#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    void enqueue(int value) {
        stack1.push(value);
    }

    int dequeue() {
        if (stack1.empty() && stack2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int front = stack2.top();
        stack2.pop();
        return front;
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl;  // Output: 10
    cout << q.dequeue() << endl;  // Output: 20

    q.enqueue(40);

    cout << q.dequeue() << endl;  // Output: 30
    cout << q.dequeue() << endl;  // Output: 40

    cout << q.isEmpty() << endl;  // Output: 1 (true)

    return 0;
}