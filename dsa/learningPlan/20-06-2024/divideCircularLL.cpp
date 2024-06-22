#include <iostream>

using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
};

// Function to split circular linked list into two halves
void splitCircularLinkedList(Node* head, Node** head1, Node** head2) {
    if (head == NULL)
        return;

    Node* slow_ptr = head;
    Node* fast_ptr = head;

    // Move fast_ptr to the end and slow_ptr to the middle of the list
    while (fast_ptr->next != head && fast_ptr->next->next != head) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    // If the list has odd number of nodes, move fast_ptr one more step
    if (fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;

    // Set the head of the first half
    *head1 = head;

    // Set the head of the second half
    if (head->next != head)
        *head2 = slow_ptr->next;

    // Make the second half circular
    fast_ptr->next = slow_ptr->next;

    // Make the first half circular
    slow_ptr->next = head;
}

// Function to print a circular linked list
void printCircularLinkedList(Node* head) {
    if (head == NULL)
        return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int main() {
    // Create a circular linked list
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = head;

    // Split the circular linked list into two halves
    Node* head1 = NULL;
    Node* head2 = NULL;
    splitCircularLinkedList(head, &head1, &head2);

    // Print the first half
    cout << "First Half: ";
    printCircularLinkedList(head1);
    cout << endl;

    // Print the second half
    cout << "Second Half: ";
    printCircularLinkedList(head2);
    cout << endl;

    return 0;
}