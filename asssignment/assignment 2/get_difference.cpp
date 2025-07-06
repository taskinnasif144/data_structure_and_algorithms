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

void insert_at_tail(Node *&head, Node *&tail, int value, int &max, int &min)
{
    Node *newNode = new Node(value);
    if(value < min) {
        min = value;
    }
    if(value > max) {
        max = value;
    }
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



int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int max = INT_MIN;
    int min = INT_MAX;
    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val, max, min);
    }
    cout << max - min;
    return 0;
}