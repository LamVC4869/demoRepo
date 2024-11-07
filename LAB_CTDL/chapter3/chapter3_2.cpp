#include <iostream>

using namespace std;

class Node {
private:
    int data;
    Node* next;
    friend class LinkedList;
public:
    Node() {}
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    void push_back (int x) {
        if (!head && !tail) {
            head = tail = new Node(x);
            return;
        }
        tail->next = new Node(x);
        tail = tail->next;
    }
    void push_front (int x) {
        if (!head && !tail) {
            head = tail = new Node(x);
            return;
        }
        Node* ptr = new Node(x);
        ptr->next = head;
        head = ptr;
    }
    bool found (int x) const {
        Node* ptr = head;
        while (ptr) {
            if (ptr->data == x)
                return true;
            ptr = ptr->next;
        }
        return false;
    }
    void pop_front () {
        if (!head && !tail) return;
        if (head == tail) {
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    LinkedList operator = (const LinkedList& another) {
        LinkedList L;
        Node* ptr = another.head;
        while (ptr) {
            L.push_back(ptr->data);
            ptr = ptr->next;
        }
        return L;
    }
    LinkedList concatenate (const LinkedList& L1, const LinkedList& L2) {
        LinkedList L3 = L2;
        Node* ptr = L1.head;
        while (ptr) {
            L3.push_back(ptr->data);
            ptr = ptr->next;
        }
        return L3;
    }
    LinkedList List_difference (const LinkedList& L1, const LinkedList& L2) {
        LinkedList L3;
        Node* ptr = L1.head;
        while (ptr) {
            if (!L2.found(ptr->data)) {
                L3.push_back(ptr->data);
            }
            ptr = ptr->next;
        }
        return L3;
    }
    LinkedList List_intersection (const LinkedList& L1, const LinkedList& L2) {
        LinkedList L3;
        Node* ptr = L1.head;
        while (ptr) {
            if (L2.found(ptr->data)) {
                L3.push_back(ptr->data);
            }
            ptr = ptr->next;
        }
        return L3;
    }
    LinkedList List_union (const LinkedList& L1, const LinkedList& L2) {
        LinkedList L3;
        for (Node* ptr = L1.head; ptr != nullptr; ptr = ptr->next) {
            if (!L3.found(ptr->data)) {
                L3.push_back(ptr->data);
            }
        }
        for (Node* ptr = L2.head; ptr != nullptr; ptr = ptr->next) {
            if (!L3.found(ptr->data)) {
                L3.push_back(ptr->data);
            }
        }
        return L3;
    }
    LinkedList SUM (const LinkedList& L1, const LinkedList& L2) {
        LinkedList L3;
        Node* p1 = L1.head;
        Node* p2 = L2.head;
        while (p1 && p2) {
            L3.push_back(p1->data + p2->data);
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1) {
            L3.push_back(p1->data);
            p1 = p1->next;
        }
        while (p2) {
            L3.push_back(p2->data);
            p2 = p2->next;
        }
        return L3;
    }
    bool trungGiaTri (const LinkedList& L1, const LinkedList& L2) {
        for (Node* p = L1.head;  p != nullptr; p = p->next) {
            if (L2.found(p->data))
                return true;
        }
        return false;
    }
    int MAX_VALUE () const {
        Node* p = head;
        int result = p->data;
        while (p) {
            result = max(result, p->data);
            p = p->next;
        }
        return result;
    }
    int sum () const {
        int result = 0;
        for (Node* p = head; p != nullptr; p = p->next) {
            result += p->data;
        }
        return result;
    }
    void removeFirstElement (const LinkedList& L2) {
        if (!head) return;
        int sumOfList = L2.sum();
        Node* p = head;
        if (p->data > sumOfList) {
            pop_front();
            return;
        }
        Node* pre = p;
        p = p->next;
        while (p) {
            if (p->data > sumOfList) {
                pre->next = p->next;
                if (!pre->next) tail = pre;
                delete p;
                break;
            }
            p = p->next;
            pre = pre->next;
        }
    }
    void remove (const LinkedList& L2) {
        if (!head) return;
        int MAX = L2.MAX_VALUE();
        while (head && head->data == MAX) {
            pop_front();
        }
        if (!head) return;
        Node* pre = head;
        Node* curr = pre->next;
        while (curr) {
            if (curr->data == MAX) {
                pre->next = curr->next;
                delete curr;
                curr = pre->next;
            }
            else {
                pre = pre->next;
                curr = curr->next;
            }
        }
    }
    ~LinkedList() {
        Node* p = nullptr;
        while (head) {
            p = head;
            head = head->next;
            delete p;
        }
        tail = nullptr;
    }
};

void Menu (LinkedList& L1, LinkedList& L2) {
    return;
}

int main () {
    LinkedList L1, L2;
    Menu(L1, L2);
    return (1 & 0);
}