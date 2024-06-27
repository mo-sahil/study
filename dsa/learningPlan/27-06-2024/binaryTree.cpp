#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

void postOrder(Node* root) {
    if(root == NULL) return;

    postOrder(root -> left);
    postOrder(root -> right);

    cout << root -> data << " ";
}

void inOrder(Node* node) {
    if(node == NULL) return;

    inOrder(node -> left);

    cout << node -> data << " ";

    inOrder(node -> right);
}

void preOrder(Node* node) {
    if(node == NULL) return;

    cout << node -> data << " ";

    inOrder(node -> left);

    inOrder(node -> right);
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    postOrder(root);

    cout << endl;

    inOrder(root);

    cout << endl;

    preOrder(root);    
}