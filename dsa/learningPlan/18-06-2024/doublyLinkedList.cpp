#include <iostream>

using namespace std;

class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtBeginning(int value) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Unable to delete." << endl;
            return;
        }
        ListNode* temp = head;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty. Unable to delete." << endl;
            return;
        }
        ListNode* temp = tail;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    // Added a function to print the list
    void printList() const {
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtBeginning(5);
    list.insertAtBeginning(10);
    list.insertAtEnd(15);
    list.insertAtEnd(20);

    list.printList(); // Use the member function to print the list

    list.deleteAtBeginning();
    list.deleteAtEnd();

    list.printList(); // Print the list again after deletions

    return 0;
}