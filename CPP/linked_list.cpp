#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    struct Node *head = new Node();
    struct Node *second = new Node();
    struct Node *last = new Node();

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = last;

    last->data = 6;
    last->next = NULL;

    traversal(head);

    delete head;
    delete second;
    delete last;
    
    return 0;
}