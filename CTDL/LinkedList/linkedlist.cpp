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

struct LinkedList {
    node head = nullptr;
    int size ();
    void push_back (node k);
    void push_front (node k);
    void pop_back ();
    void pop_front ();
    void reverse ();
    void print ();
    void sort ();
    void insert (int x, int k);
    void remove (int k);
    int get (int k);
    bool empty ();
    ~LinkedList ();
};

void LinkedList::push_back (node k) {
    if (head == nullptr) {
        head = k;
        return;
    }
    node curr = head;
    while (curr->next != nullptr) curr = curr->next;
    curr->next = k;
}

void LinkedList::push_front (node k) {
    if (head == nullptr) {
        head = k;
        return;
    }
    k->next = head;
    head = k;
}

void LinkedList::pop_back () {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    node curr = head;
    while (curr->next->next != nullptr) curr = curr->next;
    node temp = curr->next;
    curr->next = nullptr;
    delete temp;
}

void LinkedList::pop_front () {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        node temp = head;
        head = nullptr;
        delete temp;
        return;
    }
    node temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::print () {
    node curr = head;
    while (curr != nullptr) {
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << '\n';
}

void LinkedList::reverse () {
    node prev = nullptr;
    node curr = head;
    node next = curr;
    while (next != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void LinkedList::sort () {
    node curr = head;
    while (curr->next != nullptr) {
        bool swapped = true;
        node next = curr->next;
        while (next != nullptr) {
            if (curr->data > next->data) {
                swapped = false;
                swap(curr->data, next->data);
            }
            next = next->next;
        }
        if (swapped) break;
        curr = curr->next;
    }
}

int LinkedList::size () {
    int size = 0;
    node curr = head;
    while (curr != nullptr) {
        ++size;
        curr = curr->next;
    }
    return size;
}

LinkedList::~LinkedList () {
    node curr = nullptr;
    while (head != nullptr) {
        curr = head;
        head = head->next;
        delete curr;
    }
}

void LinkedList::insert (int x, int k) {
    node p = make_node(x);
    if (k == 0) this->push_front(p);
    else if (k == this->size()) this->push_back(p);
    else {
        node curr = head;
        for (int i = 0; i < k - 1; ++i) {
            curr = curr->next;
        }
        p->next = curr->next;
        curr->next = p;
    }
}

void LinkedList::remove (int k) {
    if (k == 0) {
        this->pop_front();
        return;
    }
    node curr = head;
    for (int i = 0; i < k - 1; ++i) {
        curr = curr->next;
    }
    node temp = curr->next;
    curr->next = temp->next;
    delete temp;
}

int LinkedList::get (int k) {
    int total;
    node curr = head;
    for (int i = 0; i < k; ++i) {
        curr = curr->next;
    }
    total = curr->data;
    return total;
}

bool LinkedList::empty () {
    return head == nullptr;
}

void solve (LinkedList &myList, int k) {
    int value = myList.get(k);
    while (!myList.empty() && myList.head->data > value) {
        myList.pop_front();
    }
    if (myList.empty()) return;
    node prev = myList.head;
    node curr = prev->next;
    while (curr != nullptr) {
        if (curr->data > value) {
            node temp = curr;
            prev->next = temp->next;
            curr = prev->next;
            delete temp;
        }
        else {
            curr = curr->next;
            prev = prev->next;
        }
    }
    myList.print();
}

int main () {
    LinkedList myList;
    int n, k; cin >> n;
    for (int i = 0; i < n; ++i) {
        int digit; cin >> digit;
        myList.push_back(make_node(digit));
    }
    cin >> k;
    solve(myList, k);
}