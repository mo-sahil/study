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

struct node * insert(struct node *head, int data, int index){
    struct node *p = head;
    struct node *ptr = new node();

    int i=0;
    while (i!=index-1){
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;

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

    insert(head, 54, 2);
    traversal(head);

    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}