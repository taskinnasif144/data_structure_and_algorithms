#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    long long int val;
    Node *next;

    Node(long long int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    if (tail == NULL)
    {
        tail = head;
    }
}

void print_linked_list(Node *head)
{
    Node *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

void delete_at_idx(Node *&head, Node *&tail, int idx)
{
    if (head == NULL)
        return;
    if (idx == 0)
    {
        Node * deleteNode = head;
        head = head->next;
        if (head == NULL)
            tail = NULL; 
        delete  deleteNode;
        return;
    }
    Node *current = head;
    for (int i = 1; i < idx; i++)
    {
        if (current == NULL || current->next == NULL)
            return; 
        current = current->next;
    }
    if (current->next == NULL)
        return; 
    Node *delNode = current->next;
    current->next = current->next->next;
    if (current->next == NULL)
        tail = current; 
    delete delNode;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int x;
        long long int v;
        cin >> x >> v;
        switch (x)
        {
        case 0:
            insert_at_head(head, tail, v);
            print_linked_list(head);
            break;

        case 1:
            insert_at_tail(head, tail, v);
            print_linked_list(head);
            break;

        case 2:
            delete_at_idx(head, tail, v);
            print_linked_list(head);
            break;

        default:
            break;
        }
    }

    return 0;
}