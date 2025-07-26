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

class Stack
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void push(int val)
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

    int pop()
    {
        if (head == NULL)
            return -1;
        int popedVal = tail->val;
        Node *deleteNode = tail;
        if (!tail->prev)
        {
            head = NULL;
            tail = NULL;
            return popedVal;
        }
        tail = tail->prev;
        tail->next = NULL;
        delete deleteNode;
        return popedVal;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    int top()
    {
        return tail->val;
    }
};

class Queue
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void push(int val)
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

    int pop()
    {
        if (head == NULL)
            return -1;
        Node *deleteNode = head;
        int popedValue = head->val;
        if(!head->next){
            head = NULL;
            tail = NULL;
            return popedValue;
        }
        head = head->next;
        head->prev = NULL;
        delete deleteNode;
        return popedValue;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    int front()
    {
        return head->val;
    }
};

bool isSame(Stack A, Queue B)
{
    while (!A.isEmpty() && !B.isEmpty())
    {
        if (A.top() != B.front())
            return false;
        A.pop();
        B.pop();
    }

    return true;
}
int main()
{
    int N, M;
    cin >> N >> M;
    int sizeN = N, sizeM = M;
   Stack stack;
   Queue queue;
    while (N--)
    {
        int val;
        cin >> val;
        stack.push(val);
    }
    while (M--)
    {
        int val;
        cin >> val;
        queue.push(val);
    }
    if (sizeN == sizeM)
    {
        if (isSame(stack, queue))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}