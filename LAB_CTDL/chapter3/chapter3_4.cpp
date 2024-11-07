#include <iostream>

using namespace std;

class Node {
private:
    int data;
    Node* next;
    friend class LinkedList;
public:
    Node(int x) : data(x), next(nullptr) {}
};

class LinkedList {
private:
    Node* root;
public:
    LinkedList() : root(nullptr) {}
    void push_back (int x) {
        if (!root) {
            root = new Node(x);
            return;
        }
        Node* current = root;
        while (current->next)
            current = current->next;
        current->next = new Node(x);
    }
    void interchangeSort () {
        for (Node* current = root; current->next != nullptr; current = current->next)
            for (Node* next = current->next; next != nullptr; next = next->next)
                if (current->data > next->data)
                    swap(current->data, next->data);
    }
    bool found (int x) const {
        for (Node* current = root; current != nullptr; current = current->next)
            if (current->data == x)
                return true;
        return false;
    }
    LinkedList operator = (const LinkedList& another) {
        LinkedList List;
        Node* current = another.root;
        while (current) {
            List.push_back(current->data);
            current = current->next;
        }
        return List;
    }
    //Phép hiệu
    LinkedList List_difference (const LinkedList& L1, const LinkedList& L2) {
        LinkedList L3;
        for (Node* current = L1.root; current != nullptr; current = current->next)
            if (!L2.found(current->data)) 
                L3.push_back(current->data);
        L3.interchangeSort();
        return L3;
    }
    //Phép giao
    LinkedList List_intersection (const LinkedList& L1, const LinkedList& L2) {
        LinkedList L3;
        for (Node* current = L1.root; current != nullptr; current = current->next)
            if (L2.found(current->data))
                L3.push_back(current->data);
        L3.interchangeSort();
        return L3;
    }
    //Phép hợp
    LinkedList List_union (const LinkedList& L1, const LinkedList& L2) {
        LinkedList L3;
        for (Node* current = L1.root; current != nullptr; current = current->next)
            if (!L3.found(current->data))
                L3.push_back(current->data);
        for (Node* current = L2.root; current != nullptr; current = current->next)
            if (!L3.found(current->data))
                L3.push_back(current->data);
        L3.interchangeSort();
        return L3;
    }
    void display () {
        for (Node* current = root; current != nullptr; current = current->next)
            cout << current->data << ' ';
    }
    void clear() {
        while (root) {
            Node* temp = root;
            root = root->next;
            delete temp;
        }
    }
    ~LinkedList() {
        this->clear();
    }
};

int main () {
    
    return 0;
}