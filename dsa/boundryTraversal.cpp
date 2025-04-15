#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    char val;
    Node *left;
    Node *right;

    Node(char val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void buildTree(Node *&root)
{
    root = new Node('a');
    root->left = new Node('b');
    root->right = new Node('k');
    root->left->left = new Node('c');
    root->left->right = new Node('h');
    root->right->left = new Node('j');
    root->right->right = new Node('l');
    root->right->right->left = new Node('m');
    root->right->right->right = new Node('n');
    root->left->left->right = new Node('g');
    root->left->left->left = new Node('d');
    root->left->left->left->right = new Node('f');
    root->left->left->left->right->right = new Node('e');
}

void left(Node *root)
{
    if (!root)
        return;

    if (root->left)
    {
        cout << root->val << " ";
        left(root->left);
    }

    else if (root->right)
    {
        cout << root->val << " ";
        left(root->right);
    }
}

void printLeaf(Node *root)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        cout << root->val << " ";
    }

    printLeaf(root->left);
    printLeaf(root->right);
}

void right(Node *root, vector<char> &arr)
{
    if (!root)
        return;

    if (!root->left && !root->right)
        return;

    if (root->right)
    {
        arr.push_back(root->val);
        right(root->right, arr);
    }
}

void printRight(Node *root)
{
    vector<char> arr;
    right(root, arr);

    for (int i = arr.size() - 1; i > 0; i--)
        cout << arr[i] << " ";
}

void printBoundryTraversal(Node *root)
{
    left(root);
    printLeaf(root);
    printRight(root);
}

int main()
{
    Node *root = NULL;
    buildTree(root);
    printBoundryTraversal(root);
}