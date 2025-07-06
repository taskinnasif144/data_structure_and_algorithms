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

void insert_at_tail(Node *&head, Node *&tail, int value, int &size)
{
    Node *newNode = new Node(value);
    size+= 1;

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

bool compare_two_list(Node* head1, Node* head2, int size1, int size2) {
    if(size1 != size2) return false;

    Node* current1 = head1;
    Node* current2 = head2;

    while (current1 && current2) {
        if(current1->val != current2->val) return false;
        current1 = current1->next;
        current2 = current2->next;
    }
  
    return true;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;

    int size1 = 0;
    int size2 = 0;

    while (true)
    {
        long long int val;
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val, size1);
    }
   
    while (true)
    {
        long long int val;
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head2, tail2, val, size2);
    }
   
    bool isSame = compare_two_list(head, head2, size1, size2);

    cout << (string)(isSame? "YES" : "NO");
    return 0;
}