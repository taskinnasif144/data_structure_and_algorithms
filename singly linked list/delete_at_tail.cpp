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

void print_linked_list(Node *head)
{
    Node *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
}

void delete_at_head(Node* &head){
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
}

void delete_at_tail(Node* &head, Node* &tail){
    Node* lastNode = head;
    while(lastNode->next->next) {
        lastNode = lastNode->next;
    }
    tail = lastNode;
    Node* deleteNode = lastNode->next;
    tail->next = NULL;
    delete deleteNode;
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
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }
    delete_at_tail(head, tail);
    delete_at_tail(head, tail);
    delete_at_tail(head, tail);
    print_linked_list(head);
    return 0;
}