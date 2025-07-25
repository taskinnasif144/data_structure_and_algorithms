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

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    Node *currentHead = head;
    newNode->next = currentHead;
    currentHead->prev = newNode;
    head = newNode;
}

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

bool insert_at_any_position(Node *&head, Node *&tail, int idx, int val)

{
    if (idx == 0)
    {
        insert_at_head(head, tail, val);
        return true;
    }
    if (!head)
    {
        cout << "Invalid" << endl;
        return false;
    }
    Node *currentNode = head;
    for (int i = 1; i < idx; i++)
    {
        if (!currentNode->next)
        {
            cout << "Invalid" << endl;
            return false;
        };
        currentNode = currentNode->next;
    }

    Node *newNode = new Node(val);

    if (currentNode == tail)
    {
        tail = newNode;
    }

    newNode->next = currentNode->next;
    if (currentNode->next)
    {
        currentNode->next->prev = newNode;
    }
    currentNode->next = newNode;
    newNode->prev = currentNode;

    return true;
}

void print_all_nodes(Node *head)
{
    Node *current = head;
    if (head)
        cout << "L -> ";
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    if (head)
        cout << endl;
}

void print_all_nodes_reverse(Node *tail)
{
    Node *current = tail;
    if (tail)
        cout << "R -> ";
    while (current)
    {
        cout << current->val << " ";
        current = current->prev;
    }
    if (tail)
        cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int q;
    cin >> q;
    while (q--)
    {
        int idx, val;
        cin >> idx >> val;
        bool isValid = insert_at_any_position(head, tail, idx, val);
        if (isValid)
        {
            print_all_nodes(head);
            print_all_nodes_reverse(tail);
        }
    }
    return 0;
}