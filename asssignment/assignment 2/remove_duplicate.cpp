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
        Node *deleteNode = head;
        head = head->next;
        if (head == NULL)
            tail = NULL;
        delete deleteNode;
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

void delete_duplicated(Node *&head, Node *&tail)
{
    Node *current = head;
    while (current)
    {
        Node *temp = current->next;
        Node *prev = current;
        while (temp)
        {
            if (current->val == temp->val)
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
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

    delete_duplicated(head, tail);
    print_linked_list(head);

    return 0;
}