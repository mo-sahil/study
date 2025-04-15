#include <iostream>
#include <stack>
#include <string>
#include <climits>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    root->data = 50;
    root->left = new node(40);
    root->right = new node(60);
    root->left->left = new node(30);
    root->left->right = new node(45);
    root->left->left->left = new node(25);
    root->left->left->right = new node(45);

    return root;
}

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void inorderIterative(node *root)
{
    stack<node *> s;
    while (root != NULL || !s.empty())
    {
        while (root != NULL)
        {
            s.push(root);
            root = root->left;
        }

        root = s.top();
        s.pop();

        cout << root->data << " ";
        root = root->right;
    }
}

int isValid = true;

void isBST(node *root, int minimum, int maximum)
{
    if (root == NULL || !isValid)
        return;

    if (root->data <= minimum || root->data >= maximum)
    {
        isValid = false;
        return;
    }

    isBST(root->left, minimum, root->data);
    isBST(root->right, root->data, maximum);
}

int main()
{
    node *root = NULL;

    cout << "Enter data: " << endl;
    root = buildTree(root);

    cout << "inorder traversal: " << endl;
    inorderIterative(root);
    cout << endl;

    isBST(root, INT_MIN, INT_MAX);
    cout << isValid << endl;

    return 0;
}