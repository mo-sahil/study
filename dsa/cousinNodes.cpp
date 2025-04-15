#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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
    root = new Node(10);
    root->left = new Node(4);
    root->right = new Node(40);
    root->left->left = new Node(2);
    root->left->right = new Node(20);
    root->right->left = new Node(45);
    root->right->right = new Node(50);
    root->left->right->left = new Node(7);
    root->left->left->left = new Node(60);
    root->right->left->left = new Node(55);
    root->left->right->right = new Node(35);
    root->right->right->right = new Node(70);

    return root;
}

Node *x_parent = NULL;
Node *y_parent = NULL;
int x_lvl = -1, y_lvl = -1;

void findCousins(Node *root, Node *x, Node *y, int lvl, Node *parent)
{
    if (!root || (x_parent && y_parent))
        return;

    if (root == x)
    {
        x_parent = parent;
        x_lvl = lvl;
        return;
    }

    if (root == y)
    {
        y_parent = parent;
        y_lvl = lvl;
        return;
    }

    findCousins(root->left, x, y, lvl + 1, root);
    findCousins(root->right, x, y, lvl + 1, root);
}

bool areCousins(Node *root, Node *x, Node *y)
{
    findCousins(root, x, y, 0, NULL);
    return (x_lvl == y_lvl) && (x_parent != y_parent);
}

int main()
{
    Node *root = nullptr;
    root = buildTree(root);

    Node *x = root->right->left;
    Node *y = root->right->right;

    cout << (areCousins(root, x, y) ? "Cousins" : "Not Cousins") << endl;

    return 0;
}