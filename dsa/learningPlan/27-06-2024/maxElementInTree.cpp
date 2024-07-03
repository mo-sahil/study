#include <bits/stdc++.h>
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

int maxElementinTree(Node* node) {
    if(node == NULL) return INT_MIN;

    int res = node -> data;

    int lres = maxElementinTree(node -> left);
    int rres = maxElementinTree(node -> right);

    if(lres > res) res = lres;
    if(rres > res) res = rres;

    return res;
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    cout << "Max Element of tree is " << maxElementinTree(root) << endl;   
}