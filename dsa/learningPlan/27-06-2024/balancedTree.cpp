#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this -> data = data;
        Node* left = NULL;
        Node* right = NULL;
    }
};

int isBalanced(Node* root)
{
	if (root == NULL)
		return 0;
	int lh = isBalanced(root->left);
	if (lh == -1)
		return -1;
	int rh = isBalanced(root->right);
	if (rh == -1)
		return -1;

	if (abs(lh - rh) > 1)
		return -1;
	else
		return max(lh, rh) + 1;
}

bool checkBalanced(Node* root) {
    return isBalanced(root) != -1;
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> left -> left -> left = new Node(6);

    cout << "Tree is height Balanced : " << (checkBalanced(root) ? "Yes" : "No") << endl;    
}