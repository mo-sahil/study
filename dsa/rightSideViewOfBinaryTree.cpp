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
    root->left = new Node(20);
    root->right = new Node(2);
    root->left->right = new Node(40);
    root->right->right = new Node(4);
    root->left->right->left = new Node(7);
    root->right->right->left = new Node(5);
    root->right->right->right = new Node(6);
    root->left->right->left->right = new Node(8);

    return root;
}

void rightSideView(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *cur = q.front();
            q.pop();

            if (i == n - 1)
                cout << cur->val << " ";

            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }
}

void rightSideViewWithDFS(Node *root, vector<Node *> &v, int level)
{
    if (!root)
        return;

    if (v.size() == level)
        v.push_back(root);

    rightSideViewWithDFS(root->right, v, level + 1);
    rightSideViewWithDFS(root->left, v, level + 1);
}

void rightSideViewWithNormalDFS(Node *root, vector<int> &v, int level)
{
    if (!root)
        return;

    if (level == v.size())
        v.push_back(root->val);
    else
        v[level] = root->val;
    rightSideViewWithNormalDFS(root->left, v, level + 1);
    rightSideViewWithNormalDFS(root->right, v, level + 1);
}

int main()
{
    Node *root = nullptr;
    root = buildTree(root);
    // rightSideView(root);
    vector<int> v;
    // rightSideViewWithDFS(root, v, 0);
    rightSideViewWithNormalDFS(root, v, 0);

    for (auto i : v)
        cout << i << " ";

    return 0;
}