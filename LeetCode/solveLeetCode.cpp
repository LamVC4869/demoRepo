#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:

    bool nutLa (Node* root) {
        return root->children.empty();
    }
    void DFS (Node* root, int& depth, int len) {
        if (!root) return;
        if (nutLa(root))  {
            depth = max(depth, len);
            return;
        }
        for (auto it : root->children) {
            DFS(it, depth, len + 1);
        }
    }
    int maxDepth(Node* root) {
        if (!root) return 0;
        if (nutLa(root)) return 1;
        int k = 0;
        DFS(root, k, 1);
        return k;
    }
};


int main () {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    //Solution temp;
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
}