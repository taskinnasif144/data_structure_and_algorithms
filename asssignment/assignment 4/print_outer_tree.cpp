#include <bits/stdc++.h>
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

Node *inputNode()
{
    int val;
    cin >> val;
    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();

        int left;
        int right;
        cin >> left >> right;
        Node *leftNode;
        Node *rightNode;
        if (left == -1)
            leftNode = NULL;
        else
            leftNode = new Node(left);
        if (right == -1)
            rightNode = NULL;
        else
            rightNode = new Node(right);
        parent->left = leftNode;
        parent->right = rightNode;

        if (parent->left)
            q.push(leftNode);
        if (parent->right)
            q.push(rightNode);
    }

    return root;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();

        cout << parent->val << " ";

        if (parent->left)
            q.push(parent->left);
        if (parent->right)
            q.push(parent->right);
    }
}

void printLeft(Node *root)
{
    if (root == NULL)
        return;
    if (!root->left)
    {
        printLeft(root->right);
        cout << root->val << " ";
        return;
    }
    printLeft(root->left);
    cout << root->val << " ";
}

void printRight(Node *root)
{
    if(root == NULL) return;
    cout << root->val << " ";
    if(!root->right) {
        printRight(root->left);
        return;
    }
    printRight(root->right);
}

int main()
{

    Node *root = inputNode();
    printLeft(root->left);
    cout << root->val << " ";
    printRight(root->right);
    return 0;
}