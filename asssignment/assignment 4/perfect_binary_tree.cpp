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

int heightOfTree(Node *root)
{
    if (root == NULL)
        return 0;
    int l = heightOfTree(root->left);
    int r = heightOfTree(root->right);
    return max(l, r) + 1;
}

int countNode(Node *root)
{
    if (root == NULL)
        return 0;
    int l = countNode(root->left);
    int r = countNode(root->right);
    return l + r + 1;
}

pair<int, int> perfectTree(Node *root)
{
    if (root == NULL)
        return {0, 0};
    pair<int, int> p1;
    pair<int, int> p2;
    p1 = perfectTree(root->left);
    p2 = perfectTree(root->right);
    return {max(p1.first, p2.first) + 1, p1.second + p2.second + 1 };
}

int main()
{
    Node *root = inputNode();
    // int h = heightOfTree(root);
    // int node = countNode(root);
    // int theoriticalNum = pow(2, h) - 1;
    pair<int, int> res = perfectTree(root);
    int theoriticalNum = pow(2, res.first) -1;
    if (theoriticalNum == res.second)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}