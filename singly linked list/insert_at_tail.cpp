#include<bits/stdc++.h>
using namespace std;

class Node {
    
    public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_head(Node* &head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insert_at_tail(Node* head, int value) {
    Node* newNode = new Node(value);
    Node* lastNode = head;
    while(lastNode->next) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

void print_linked_list(Node* head) {
    Node * currentNode = head;
    while(currentNode) {
        cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }
}

int main() {

    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30); 
    head->next = a;
    a->next = b;
    insert_at_head(head, 200);
    insert_at_tail(head, 40);
    insert_at_tail(head, 50);

    print_linked_list(head);
    return 0;
}