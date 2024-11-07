#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

typedef Node* node;

node make_node (int x) {
    node p = new Node;
    if (p == nullptr) return nullptr;
    p->data = x;
    p->next = nullptr;
    return p;
}

struct CircularLinkedList {
    node head = nullptr;

    bool empty () {
        return head == nullptr;
    }
    void push_back (int x) {
        node p = make_node(x);
        if (empty()) {
            head = p;
            p->next = head;
            return;
        }
        node curr = head;
        while (curr->next != head) curr = curr->next;
        curr->next = p;
        p->next = head;
    }

    void push_front (int x) {
        node p = make_node(x);
        if (empty()) {
            head = p;
            p->next = head;
            return;
        }
        node curr = head;
        while (curr->next != head) curr = curr->next;
        p->next = head;
        curr->next = p;
        head = p;
    }

    void print (int k) {
        node curr = head;
        for (int i = 0; i < k; ++i) curr = curr->next;
        cout << curr->data << ' ';
        node next = curr->next;
        while (next != curr) {
            cout << next->data << ' ';
            next = next->next;
        }
    }
};

int main () {
    CircularLinkedList myList;
    int n, k; cin >> n;
    for (int i = 0, digit; i < n; ++i) {
        cin >> digit;
        myList.push_back(digit);
    }
    cin >> k;
    myList.print(k);
}