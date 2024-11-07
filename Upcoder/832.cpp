#include <bits/stdc++.h>
#define ifile freopen("input.txt", "r", stdin)
#define ofile freopen("output.txt", "w", stdout)
#define setup(a, c) memset(a, c, sizeof(a))
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FOD(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define rz resize
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Flight {
    string id, day, time, from, to;
    friend istream& operator >> (istream &is, Flight &cb) {
        getline(is, cb.id);
        getline(is, cb.day);
        getline(is, cb.time);
        getline(is, cb.from);
        getline(is, cb.to);
        return is;
    }
    friend ostream& operator << (ostream &os, const Flight& cb) {
        os << cb.id << '_' << cb.day << '_' << cb.time << '_' << cb.from << '_' << cb.to;
        return os << '\n';
    }
};

struct Node {
    Flight data;
    Node *next;
};

typedef Node* node;

node make_node (const Flight& x) {
    node p = new Node;
    if (p == NULL) return NULL;
    p->data = x;
    p->next = NULL;
    return p;
}

struct LinkedList {
    node head = NULL;

    int size () {
        int size = 0;
        for (node p = head; p != NULL; p = p->next) {
            ++size;
        }
        return size;
    }
    void insert (const Flight& k) {
        node p = make_node(k);
        if (head == NULL) {
            head = p;
            return;
        }
        node curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = p;
    }
    void PrintTheDayWithTheMostFlights () {
        int total = 1;
        vector<int> count(this->size(), 1);
        int i = 0;
        for (node prev = head; prev->next != NULL; prev = prev->next) {
            for (node curr = prev->next; curr != NULL; curr = curr->next) {
                if (curr->data.day == prev->data.day) {
                    count[i]++;
                }
            }
            total = max(total, count[i]);
            i++;
        }
        i = 0;
        for (node p = head; p != NULL; p = p->next) {
            if (count[i] == total) {
                cout << p->data.day << '\n';
            }
            ++i;
        }
    }
    bool find (const string& newId) {
        for (node p = head; p != NULL; p = p->next) {
            if (p->data.id == newId) {
                return cout << p->data, true;
            }
        }
        return false;
    }
    void print () {
        node curr = head;
        while (curr != NULL) {
            cout << curr->data;
            curr = curr->next;
        }
    }
    ~LinkedList () {
        node p = NULL;
        while (head != NULL) {
            p = head;
            head = head->next;
            delete p;
        }
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifile;
    ofile;
    LinkedList myList;
    Flight flight;
    while (cin >> flight) myList.insert(flight);
    cin.ignore();
    string newId;
    getline(cin, newId);
    myList.print();
    myList.PrintTheDayWithTheMostFlights();
    if (!myList.find(newId)) return cout << "Khong tim thay", 0;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}