#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    Node *prev;
    int val;
    Node *next;

    Node(int val)
    {
        this->prev = NULL;
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void print_all_nodes(Node *head)
{
    Node *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

bool is_palindrome(Node *head, Node *tail)
{
    Node *left = head;
    Node *right = tail;
    while (left && left->prev != right)
    {
        if (left->val != right->val)
            return false;
        left = left->next;
        right = right->prev;
    }

    return true;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
            break;
        insert_at_tail(head, tail, val);
    }

    bool isPalindrome = is_palindrome(head, tail);

    if (isPalindrome)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}