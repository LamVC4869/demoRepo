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

bool isValid (Node* ptr) {
    return !ptr->left && !ptr->right;
}

int CountNode (Node* root) {
    if (!root) return 0;
    if (isValid(root)) return 1;
    return CountNode(root->left) + CountNode(root->right);
}

int main () {
    Node* root(nullptr);
    int n; cin >> n;
    while (n--) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    cout << CountNode(root);
    return 0;
}