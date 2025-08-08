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

void printLevelNode(Node* root, int target, int curr, bool &valid) {
    if(root == NULL) return;
    if(curr == target) {
        cout << root->val << " ";
        valid = true;
        return;
    }
    printLevelNode(root->left, target, curr +1, valid);
    printLevelNode(root->right, target, curr +1, valid);
}

int main()
{

    Node* root = inputNode();
    int targetLevel;
    cin >> targetLevel;
    bool valid = false;
    printLevelNode(root, targetLevel, 0, valid);
    if(!valid)
    cout << "Invalid" << endl;
    return 0;
}