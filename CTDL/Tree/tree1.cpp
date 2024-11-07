#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node (int data) : data(data), left(nullptr), right(nullptr) {}
};

Node* push (Node* root, int x) {
    if (!root)
        return new Node(x);
    if (x < root->data)
        root->left = push(root->left, x);
    else
        root->right = push(root->right, x);
}

void InOrder (Node* root) {
    if (!root)
        return;
    InOrder(root->left);
    cout << root->data << ' ';
    InOrder(root->right);
}

int main () {
    Node* root = nullptr;
    int n; cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        root = push(root, x);
    }
    InOrder(root);
}