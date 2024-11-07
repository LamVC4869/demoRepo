#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node (int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* insert (Node* root, int x) {
    if (!root)
        return new Node(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else 
        root->right = insert(root->right, x);
    return root;
}

int TreeLevel (Node* root) {
    if (!root) return 0;
    return 1 + max(TreeLevel(root->left), TreeLevel(root->right));
}

int main () {
    Node* root(nullptr);
    int n; cin >> n;
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        root = insert(root, x);
    }
    cout << TreeLevel(root);
    return 0;
}