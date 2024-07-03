#include <iostream>
#include <queue>
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

void levelOrder(Node* root) {
    if(root == NULL) return;

    queue<Node *> q;

    q.push(root);
    while(!q.empty()) {
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();

        if(node -> left != NULL) q.push(node -> left);
        if(node -> right != NULL) q.push(node -> right);
    }
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    levelOrder(root);

    cout << endl;
}