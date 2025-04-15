#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    return root;
}

void isSymmetricIterative(Node *root)
{
    queue<Node *> q;
    q.push(root->left);
    q.push(root->right);
    bool isValid = true;

    while (!q.empty())
    {
        Node *left = q.front();
        q.pop();
        Node *right = q.front();
        q.pop();

        if (!left && !right)
            continue;
        if (!left || !right)
        {
            isValid = false;
            break;
        }
        if (left->val != right->val)
        {
            isValid = false;
            break;
        }

        q.push(left->left);
        q.push(right->right);
        q.push(left->right);
        q.push(right->left);
    }

    if (isValid)
        cout << "Tree is Symmetric" << endl;
    else
        cout << "Tree is not Symmetric" << endl;
}

int main()
{
    Node *root = nullptr;
    root = buildTree(root);
    isSymmetricIterative(root);

    return 0;
}