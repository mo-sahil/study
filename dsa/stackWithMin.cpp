#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    int minSoFar;
    Node *next;

    Node(int val, int minVal)
    {
        this->val = val;
        this->minSoFar = minVal;
        this->next = NULL;
    }
};

class Stack
{
private:
    Node *topNode;

public:
    Stack()
    {
        topNode = NULL;
    }

    void push(int value)
    {
        if (topNode == NULL)
        {
            topNode = new Node(value, value);
            return;
        }
        int minValue = min(value, topNode->minSoFar);
        Node *newNode = new Node(value, minValue);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop()
    {
        if (topNode == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top()
    {
        if (topNode == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return topNode->val;
    }

    int getMin()
    {
        if (topNode == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return topNode->minSoFar;
    }

    bool isEmpty()
    {
        return topNode == NULL;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(5);
    st.push(3);
    st.push(4);

    cout << "Current Min: " << st.getMin() << endl;
    st.pop();
    cout << "Current Min: " << st.getMin() << endl;
    st.pop();
    cout << "Top: " << st.top() << endl;
    cout << "Current Min: " << st.getMin() << endl;

    return 0;
}