#include <iostream>
#define ifile freopen(".inp", "r", stdin)
#define ofile freopen(".out", "w", stdout)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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

    int size();
    bool empty();
    void push_back(node x);
    void push_front(node x);
    void pop_back();
    void pop_front();
    int getMAX();
    int getMIN();
    void print();
    ~LinkedList();
};

int LinkedList::size () {
    int size = 0;
    for (node curr = head; curr != nullptr; curr = curr->next) {
        ++size;
    }
    return size;
}

bool LinkedList::empty () {
    return head == nullptr;
}

void LinkedList::push_back (node x) {
    if (empty()) {
        head = x;
        return;
    }
    node curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = x;
}

void LinkedList::push_front (node x) {
    if (empty()) {
        head = x;
        return;
    }
    x->next = head;
    head = x;
}

void LinkedList::pop_back () {
    if (empty()) return;
    if (head->next == nullptr) {
        node temp = head;
        head = nullptr;
        delete temp;
        return;
    }
    node curr = head;
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }
    node temp = curr->next;
    curr->next = nullptr;
    delete temp;
}

void LinkedList::pop_front () {
    if (empty()) return;
    if (head->next == nullptr) {
        node temp = head;
        head = nullptr;
        delete temp;
    }
    node temp = head;
    head = head->next;
    delete temp;
}

int LinkedList::getMAX () {
    int total = head->data;
    for (node curr = head->next; curr != nullptr; curr = curr->next) {
        total = max(total, curr->data);
    }
    return total;
}

int LinkedList::getMIN () {
    int total = head->data;
    for (node curr = head->next; curr != nullptr; curr = curr->next) {
        total = min(total, curr->data);
    }
    return total;
}

void LinkedList::print () {
    node curr = head;
    while (curr != nullptr) {
        cout << curr->data << ' ';
        curr = curr->next;
    }
}

LinkedList::~LinkedList () {
    node p = nullptr;
    while (!empty()) {
        p = head;
        head = head->next;
        delete p;
    }
}

void printListIndex (const LinkedList &myList, int x) {
    int index = 1;
    for (node p = myList.head; p != nullptr; p = p->next) {
        if (p->data == x) {
            cout << index << ' ';
        }
        ++index;
    }
    cout << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LinkedList myList;
    int n; cin >> n;
    for (int i = 0, digit; i < n; ++i) {
        cin >> digit;
        myList.push_back(make_node(digit));
    }
    int max_element = myList.getMAX(),
        min_element = myList.getMIN();
    cout << max_element << '\n';
    printListIndex(myList, max_element);
    cout << min_element << '\n';
    printListIndex(myList, min_element);
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}