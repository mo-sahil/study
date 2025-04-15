#include <iostream>
#include <queue>
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
    root = new node(4);
    root->left = new node(9);
    root->right = new node(5);
    root->left->left = new node(2);
    root->left->right = new node(1);

    return root;
}

void preOrder(node *root, int currSum, int *sum)
{
    if (root == NULL)
        return;

    currSum *= 10;
    currSum += root->data;

    if (root->left == NULL && root->right == NULL)
    {
        *sum += currSum;
        return;
    }

    preOrder(root->left, currSum, sum);
    preOrder(root->right, currSum, sum);
}

void levelOrder(node *root, int *sum)
{
    if (!root)
        return;

    queue<pair<node *, int>> q;
    q.push({root, root->data});

    while (!q.empty())
    {
        pair<node *, int> p = q.front();
        q.pop();

        node *currentNode = p.first;
        int currentSum = p.second;

        if (!currentNode->left && !currentNode->right)
        {
            *sum += currentSum;
        }

        if (currentNode->left)
        {
            q.push({currentNode->left, currentSum * 10 + currentNode->left->data});
        }

        if (currentNode->right)
        {
            q.push({currentNode->right, currentSum * 10 + currentNode->right->data});
        }
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);

    int sum = 0;

    // preOrder(root, 0, &sum);
    levelOrder(root, &sum);

    cout << "Sum: " << sum << endl;

    return 0;
}