#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int value, int &size)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        size += 1;
        return;
    }
    tail->next = newNode;
    size += 1;
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
}

int main()
{
    int size = 0;
    int size2 = 0;
    Node *head = NULL;
    Node *tail = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;

    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val, size);
    }

    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head2, tail2, val, size2);
    }

    cout << (bool)(size == size2);

    return 0;
}