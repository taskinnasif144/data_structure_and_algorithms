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

void insert_at_tail(Node *&head, Node *&tail, long long int value)
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

int search_target(Node* head, long long int target){
    // if(head->val == target) return 0;
    Node * current = head;
    int index = 0;
    while(current) {
        if(current->val == target) return index;
        current = current->next;
        index++;
    }

    return -1;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        Node *head = NULL;
        Node *tail = NULL;
        while (true)
        {
            long long int val;
            cin >> val;
            if (val == -1)
            {
                break;
            }
            insert_at_tail(head, tail, val);
        }
        long long int target;
        cin >> target;

        int index = search_target(head, target);
        cout << index << endl;

    }
    return 0;
}