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

Node *binaryTreeInput()
{
    int val;
    cin >> val;
    Node *root = new Node(val);
    queue<Node *> bTree;
    bTree.push(root);

    while (!bTree.empty())
    {
        Node *parent = bTree.front();
        bTree.pop();
        int l, r;
        cin >> l >> r;
        Node *myleft;
        Node *myRight;
        if (l == -1)
            myleft = NULL;
        else
            myleft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);
        parent->left = myleft;
        parent->right = myRight;

        if (parent->left)
            bTree.push(parent->left);
        if (parent->right)
            bTree.push(parent->right);
    }
    return root;
}

int countNodes(Node *root)
{
    if(root == NULL) return 0;
    int l = countNodes(root->left);
    int r = countNodes(root->right);
    return l + r + 1;
}

int countLeadNodes(Node *root)
{
    if(root == NULL) return 0;
    if(!root->left && !root->right ) return 1;
    int l = countLeadNodes(root->left);
    int r = countLeadNodes(root->right);
    return l+r;
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

int main()
{

    Node *root = binaryTreeInput();
    levelOrderTraversal(root);
    cout << endl;
    cout << "Total Nodes: " << countNodes(root) << endl;
    cout << "Total Leaf Nodes: " << countLeadNodes(root);
    return 0;
}