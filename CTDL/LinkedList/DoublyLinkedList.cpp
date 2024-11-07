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

    bool empty ();
    int size ();
    int get (int k);
    void push_back (node k);
    void push_front (node k);
    void print ();
    void insert (int x, int k);
    ~DoublyLinkedList ();
};

bool DoublyLinkedList::empty () {
    return head == nullptr;
}

void DoublyLinkedList::push_front (node k) {
    if (empty()) {
        head = k;
        return;
    }
    k->next = head;
    head->prev = k;
    head = k;
}

void DoublyLinkedList::push_back (node k) {
    if (empty()) {
        head = k;
        return;
    }
    node curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = k;
    k->prev = curr;
}

int DoublyLinkedList::size () {
    int size = 0;
    for (node curr = head; curr != nullptr; curr = curr->next) {
        ++size;
    }
    return size;
}

int DoublyLinkedList::get (int k) {
    if (k < 0 || k >= size()) return -1;
    node curr = head;
    for (int i = 0; i < k; ++i) {
        curr = curr->next;
    }
    return curr->data;
}

DoublyLinkedList::~DoublyLinkedList () {
    node p = nullptr;
    while (head != nullptr) {
        p = head;
        head = head->next;
        delete p;
    }
}

void DoublyLinkedList::print () {
    for (node curr = head; curr != nullptr; curr = curr->next) {
        cout << curr->data << ' ';
    }
    cout << '\n';
}

void DoublyLinkedList::insert (int x, int k) {
    if (k < 0 || k > size()) return;
    node p = make_node(x);
    if (k == 0) {
        push_front(p);
    }
    else if (k == size()) {
        push_back(p);
    }
    else {
        node curr = head;
        for (int i = 0; i < k - 1; ++i) {
            curr = curr->next;
        }
        p->next = curr->next;
        curr->next->prev = p;
        curr->next = p;
        p->prev = curr;
    }
}

int main () {
    DoublyLinkedList myList;
    int n, x, k; cin >> n;
    for (int i = 0; i < n; ++i) {
        int digit;
        cin >> digit;
        myList.push_back(make_node(digit));
    }
    cin >> k >> x;
    myList.insert(x, k);
    myList.print();
}