#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Node {
    string data;
    Node *next;
    Node *prev;
};

typedef Node* node;

node make_node (const string& str) {
    node p = new Node;
    if (p == nullptr) return nullptr;
    p->data = str;
    p->next = nullptr;
    p->prev = nullptr;
}

struct KNY {
    node root = nullptr;
    void push_back (const string& str) {
        node p = make_node(str);
        if (root == nullptr) {
            root = p;
            root->next = root;
            root->prev = root;
            return;
        }
        node curr = root->prev;
        curr->next = p;
        p->next = root;
        root->prev = p;
        p->prev = curr;
    }
    int leftDistance (const string& skill) {
        if (root->data == skill) return 0;
        node curr = root->prev;
        int index = -1;
        while (curr != root) {
            if (curr->data == skill) {
                break;
            }
            --index;
            curr = curr->prev;
        }
        return index;
    }
    int rightDistance (const string& skill) {
        if (root->data == skill) return 0;
        node curr = root->next;
        int index = 1;
        while (curr != root) {
            if (curr->data == skill) {
                break;
            }
            ++index;
            curr = curr->next;
        }
        return index;
    }

    // move to right -> option = true
    // move to left -> option = false
    void MoveToSkill (int steps) {
        if (steps == 0) return;
        bool option = steps > 0;
        node curr = root;
        //solve right road
        if (option) {
            for (int i = 1; i <= steps; ++i) {
                curr = curr->next;
            }
            root = curr;
            return;
        }
        else {
            steps = abs(steps);
            for (int i = 1; i <= steps; ++i) {
                curr = curr->prev;
            }
            root = curr;
            return;
        }
    }
};

const string skills[] = {
                        "", "Vien Vu", "Bich La Thien",
                        "Liet Nhat Hong Kinh", "Chuoc Cot Viem Duong", "Duong Hoa Dot",
                        "Nhat Van Chi Long", "Ta Duong Chuyen Than", "Phi Luan Duong Viem",
                        "Huy Huy An Quang", "Hoa Xa", "Huyen Nhat Hong", "Viem Vu", "Vien Vu Den Viem Vu"
                        };

int main () {
    KNY myList;
    for (const string& skill: skills) {
        myList.push_back(skill);
    }
    vector<int> Min_index;
    int n; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string skill;
        getline(cin, skill);
        int left = myList.leftDistance(skill);
        int right = myList.rightDistance(skill);
        int compare = min(abs(left), right);
        if (right == compare) {
            Min_index.push_back(right);
            myList.MoveToSkill(right);
        }
        else {
            Min_index.push_back(left);
            myList.MoveToSkill(left);
        }
    }
    for (const int& index : Min_index) {
        cout << index << ' ';
    }
}