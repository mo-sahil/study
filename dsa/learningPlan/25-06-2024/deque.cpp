#include <iostream>
#include <deque>
using namespace std;

class Deque {
private:
    deque<int> dq;

public:
    void insertFront(int element) {
        dq.push_front(element);
        cout << "Inserted " << element << " at the front.\n";
    }

    void insertRear(int element) {
        dq.push_back(element);
        cout << "Inserted " << element << " at the rear.\n";
    }

    void deleteFront() {
        if (dq.empty()) {
            cout << "Deque is empty. Cannot delete from front.\n";
        } else {
            cout << "Deleted " << dq.front() << " from the front.\n";
            dq.pop_front();
        }
    }

    void deleteRear() {
        if (dq.empty()) {
            cout << "Deque is empty. Cannot delete from rear.\n";
        } else {
            cout << "Deleted " << dq.back() << " from the rear.\n";
            dq.pop_back();
        }
    }

    int getFront() {
        if (dq.empty()) {
            cout << "Deque is empty. No front element.\n";
            return -1;
        } else {
            return dq.front();
        }
    }

    int getRear() {
        if (dq.empty()) {
            cout << "Deque is empty. No rear element.\n";
            return -1;
        } else {
            return dq.back();
        }
    }

    bool isEmpty() {
        return dq.empty();
    }

    void printDeque() {
        if (dq.empty()) {
            cout << "Deque is empty.\n";
        } else {
            cout << "Deque elements: ";
            for (int elem : dq) {
                cout << elem << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Deque deque;

    deque.insertFront(10);
    deque.insertRear(20);
    deque.insertFront(5);
    deque.printDeque();

    cout << "Front element: " << deque.getFront() << "\n";
    cout << "Rear element: " << deque.getRear() << "\n";

    deque.deleteFront();
    deque.printDeque();

    deque.deleteRear();
    deque.printDeque();

    cout << "Is deque empty? " << (deque.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}
