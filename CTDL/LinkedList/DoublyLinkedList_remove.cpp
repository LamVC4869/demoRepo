#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

typedef Node* node;

node make_node (int x) {
    node p = new Node;
    if (p == nullptr) return nullptr;
    p->data = x;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

struct DoublyLinkedList {
    node head = nullptr;

    bool empty () {
        return head == nullptr;
    }
    
    int size () {
        int size = 0;
        node curr = head;
        while (curr != nullptr) {
            ++size;
            curr = curr->next;
        }
        return size;
    }

    void push_back (int x) {
        node p = make_node(x);
        if (empty()) {
            head = p;
            return;
        }
        node curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = p;
        p->prev = curr;
    }

    void push_front (int x) {
        node p = make_node(x);
        if (empty()) {
            head = p;
            return;
        }
        p->next = head;
        head->prev = p;
        head = p;
    }

    void print () {
        node curr = head;
        while (curr != nullptr) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << '\n';
    }

    ~DoublyLinkedList () {
        node p = nullptr;
        while (head != nullptr) {
            p = head;
            head = head->next;
            delete p;
        }
    }

    void pop_back () {
        if (empty()) return;
        if (head->next == nullptr) {
            node temp = head;
            head = nullptr;
            delete temp;
            return;
        }
        node curr = head;
        while (curr->next->next != nullptr) curr = curr->next;
        node temp = curr->next;
        curr->next = nullptr;
        delete temp;
    }

    void pop_front () {
        if (empty()) return;
        if (head->next == nullptr) {
            node temp = head;
            head == nullptr;
            delete temp;
            return;
        }
        node temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    void remove (int k) {
        if (empty() || k < 0 || k >= size()) return;
        if (k == 0) {
            pop_front();
            return;
        }
        if (k == size() - 1) {
            pop_back();
            return;
        }
        node curr = head;
        for (int i = 0; i < k - 1; ++i) curr = curr->next;
        node temp = curr->next;
        temp->next->prev = curr;
        curr->next = temp->next;
        delete temp;
    }
};

int main () {
    DoublyLinkedList myList;
    int n, k; cin >> n;
    for (int i = 0, digit; i < n; ++i) {
        cin >> digit;
        myList.push_back(digit);
    }
    cin >> k;
    myList.remove(k);
    myList.print();
}