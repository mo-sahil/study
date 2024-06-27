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

int heightOfBT(Node* node) {
    if(node == nullptr) return 0;
    else {
        int ldepth = heightOfBT(node -> left);
        int rdepth = heightOfBT(node -> right);

        return (ldepth > rdepth ? ldepth + 1 : rdepth + 1);
    }
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    cout << "Height of Binary Tree " << heightOfBT(root) << endl;
}