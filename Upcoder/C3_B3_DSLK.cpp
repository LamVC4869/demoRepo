#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define pb push_back 

using namespace std;

void init (vector<int> &x, vector<int>& y, string &a, string &b) {
    getline(cin, a);
    getline(cin, b);
    stringstream ss1(a), ss2(b);
    while (ss1 >> a) x.pb(stoi(a));
    while (ss2 >> b) y.pb(stoi(b));
}

vector<int> Giao2Vector (vector<int> x, vector<int> y) {
    vector<int> ans;
    for (const int& elememt : x) {
        if (find(all(y), elememt) != y.end() && find(all(ans), elememt) == ans.end()) 
            ans.pb(elememt);
    }
    sort(all(ans));
    return ans;
}

vector<int> Remove (vector<int> x, vector<int> y) {
    vector<int> ans;
    int min = *min_element(all(y));
    for (const int& i : x) {
        if (i != min)
            ans.pb(i);
    }
    return ans;
}

vector<int> SubVector (vector<int> x, vector<int> y) {
    vector<int> ans;
    int i = 0;
    int n1 = x.size(), n2 = y.size();
    bool kt = false;
    while (i < n1) {
        int j = 0;
        while (j < n2) {
            if (x[i] == y[j]) {
                ans.pb(x[i]);
                ++i;
                kt = true;
            }
            ++j;
            if (kt && x[i] != y[j]) break;
        }
        if (kt) break;
        ++i;
    }
    return ans;
}   

void printVector (vector<int> v) {
    int i = 0, n = v.size();
    for (i = 0; i < n; ++i) {
        cout << v[i];
        if (i < n - 1) cout << ' ';
    }
}

signed main () {
    cin.tie(NULL) -> sync_with_stdio(false);
    string s1, s2;
    vector<int> L1, L2;
    init(L1, L2, s1, s2);
    vector<int> L3 = Giao2Vector(L1, L2);
    vector<int> L4 = SubVector(L1, L2);
    vector<int> L5 = Remove(L1, L2);
    printVector(L3);
    cout << '\n';
    printVector(L4);
    cout << '\n';
    printVector(L5);
}