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

void reversePrint(Node* head) {
    if(head == NULL) return;
    reversePrint(head->next);
    cout << head->val << " ";
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    while(true) {
        int val;
        cin >> val;
        if(val == -1) {
            break;
        }
        insert_at_tail(head, tail,val);
    }

    
    reversePrint(head);
    return 0;
}