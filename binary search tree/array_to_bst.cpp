#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* arrayToBST(vector<int> arr, int l, int r){
    if(l>r) return NULL;

    int mid = (l+r)/ 2;
    Node* root = new Node(arr[mid]);
    
    Node* leftNode = arrayToBST(arr, l, mid-1);
    Node* rightNode = arrayToBST(arr, mid+1, r);

    root->left = leftNode;
    root->right = rightNode;

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

int main() {
    int val;
    vector<int> arr;
    while(cin >> val) {
        arr.push_back(val);
    }
    Node* root = arrayToBST(arr, 0, arr.size() -1);

    levelOrderTraversal(root);
    return 0;
}