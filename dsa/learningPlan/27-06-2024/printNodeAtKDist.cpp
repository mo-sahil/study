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

void printAtKDist(Node* root, int k) {
    if(root == NULL || k < 0) return;

    if(k == 0) {
        cout << root -> data << " ";
        return;
    }

    printAtKDist(root -> left, k - 1);
    printAtKDist(root -> right, k - 1);

}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    cout << "Nodes at K distance are ";
    printAtKDist(root, 2);    
}