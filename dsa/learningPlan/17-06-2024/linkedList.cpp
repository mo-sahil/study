#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }

        Node() {
            this->data = 0;
            this->next = NULL;
        }
};

void print(Node *head) {
    Node* temp = head;
    cout << endl << "Printing Linked List: ";
    while(temp != NULL) {
        cout << " " << temp->data;
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}

void insertAtTail(Node* &head, int data){
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;

    temp -> next = new Node(data);
}

void insertAtPosition(Node* &head, int idx, int data) {
    if(idx == 0) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;

    while(--idx != 0 && temp != NULL) temp = temp->next;

    Node* newNode = new Node(data);
    if(idx != 0) {
        cout << "Cannot Insert" << endl << endl;
    } else if (temp == NULL && idx == 0) insertAtTail(head, data);
    else {
        newNode->next = temp -> next;
        temp -> next = newNode;
    }
}

int main() {

    Node* head = NULL;

    insertAtHead(head, 1);
    insertAtTail(head, 2);
    insertAtHead(head, 3);
    insertAtPosition(head, 3, 4);
    insertAtPosition(head, 0, 5);
    insertAtPosition(head, 1, 6);
    insertAtPosition(head, 2, 7);
    insertAtPosition(head, 7, 8);


    print(head);
}