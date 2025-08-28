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

Node *arrayToBST(vector<int> arr, int l, int r)
{
    if (l > r)
        return NULL;

    int mid = (l + r) / 2;
    Node *root = new Node(arr[mid]);

    Node *leftRoot = arrayToBST(arr, l, mid - 1);
    Node *rightRoot = arrayToBST(arr, mid + 1, r);

    root->left = leftRoot;
    root->right = rightRoot;

    return root;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        // store and pop the node
        Node *parent = nodeQueue.front();
        nodeQueue.pop();
        // print the node (or other operation)
        cout << parent->val << " ";
        // add the children
        if (parent->left)
            nodeQueue.push(parent->left);
        if (parent->right)
            nodeQueue.push(parent->right);
    }
}

void insertNodeBST(Node *&root, int val)
{
    if (!root)
    {
        root = new Node(val);
        return;
    }
    if (val < root->val)
    {
        if (!root->left)
        {
            root->left = new Node(val);
            return;
        }
        else
            insertNodeBST(root->left, val);
    }
    else
    {
        if (!root->right)
        {
            root->right = new Node(val);
            return;
        }
        else
            insertNodeBST(root->right, val);
    }
}

bool searchBST(Node *root, int val)
{
    if (!root)
        return false;
    if (root->val == val)
        return true;
    if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

int main()
{
    int val;
    vector<int> arr;
    while (cin >> val)
    {
        arr.push_back(val);
    }
    Node *root = arrayToBST(arr, 0, arr.size() - 1);
    insertNodeBST(root, 10);
    levelOrderTraversal(root);
    cout << searchBST(root, 200) << endl;
    return 0;
}