#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

void init (vector<int>& x, vector<int>& y, string& a, string& b) {
    getline(cin, a);
    getline(cin, b);
    stringstream ss1(a), ss2(b);
    while (ss1 >> a) x.push_back(stoi(a));
    while (ss2 >> b) y.push_back(stoi(b));
}

vector<int> Hop2Vector (vector<int> L1, vector<int> L2) {
    vector<int> ans;
    for (const int& i : L1) {
        if (find(all(ans), i) == ans.end()) {
            ans.push_back(i);
        }
    }
    for (const int& i : L2) {
        if (find(all(ans), i) == ans.end()) {
            ans.push_back(i);
        }
    }
    sort(all(ans), greater<int>());
    return ans;
}

vector<int> Hieu2Vector (vector<int> L1, vector<int> L2) {
    vector<int> ans;
    for (const int& i : L1) {
        if (find(all(L2), i) == L2.end()) {
            ans.push_back(i);
        }
    }
    int middle = int(ans.size()) >> 1;
    sort(ans.begin(), ans.begin() + middle, greater<int>());
    sort(ans.begin() + middle, ans.end());
    return ans;
}

vector<int> Tong2Vector (vector<int> L1, vector<int> L2) {
    int n = max(L1.size(), L2.size());
    vector<int> ans(n);
    while (L1.size() < n) L1.push_back(0);
    while (L2.size() < n) L2.push_back(0);
    for (int i = 0; i < n; ++i) {
        ans[i] = L1[i] + L2[i];
    }
    return ans;
}

void printVector (vector<int> L) {
    int n = L.size();
    for (int i = 0; i < n; ++i) {
        cout << L[i];
        if (i < n - 1) cout << ' ';
    }
}

signed main () {
    cin.tie(NULL) -> sync_with_stdio(false);
    string str1, str2;
    vector<int> L1, L2;
    init(L1, L2, str1, str2);
    vector<int> L3 = Hop2Vector(L1, L2);
    vector<int> L4 = Hieu2Vector(L1, L2);
    vector<int> L5 = Tong2Vector(L1, L2);
    printVector(L3);
    cout << '\n';
    printVector(L4);
    cout << '\n';
    printVector(L5);
}