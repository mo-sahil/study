#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void traversal(struct node *ptr){
    while (ptr != NULL){
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct node * insert(struct node *head, int data){
    struct node *ptr = new node();
    ptr->data = data;
    struct node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

int main()
{
    struct node *head = new node();
    struct node *second = new node();
    struct node *third = new node();
    struct node *fourth = new node();
    
    head->data = 9;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 7;
    third->next = fourth;

    fourth->data = 2;
    fourth->next = NULL;

    insert(head,32);
    traversal(head);

    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}