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

int height(Node* node) {
    if(node == nullptr) return 0;
    else {
        int ldepth = height(node -> left);
        int rdepth = height(node -> right);

        return (ldepth > rdepth ? ldepth + 1 : rdepth + 1);
    }
}

int levelWidth(Node* root, int level) {
    if (root == nullptr) return 0;

    if(level == 1) return 1;

    return levelWidth(root->left, level - 1) + levelWidth(root-> right, level - 1);
}

int maxWidth(Node* root) {
    int h = height(root);
    int mx = 0;

    for(int i = 0; i<=h; i++) {
        mx = max(mx, levelWidth(root, i));
    }

    return mx;
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);

    cout << "max Width of Binary Tree " << maxWidth(root) << endl;
}