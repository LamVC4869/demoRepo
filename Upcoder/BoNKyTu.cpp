#include <bits/stdc++.h>
#define ifile freopen(".inp", "r", stdin)
#define ofile freopen(".out", "w", stdout)
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

void solve (string &str, int n) {
    map<char, int> mp;
    for (char c : str) mp[c]++;
    priority_queue<int> pq;
    for (auto i : mp) pq.push(i.se);
    while (n && !pq.empty()) {
        int k = pq.top();
        pq.pop();
        k--;
        n--;
        if (k > 0) pq.push(k);
    }
    ull f = 0;
    while (!pq.empty()) {
        f += 1LL*(pow(pq.top(), 2));
        pq.pop();
    }
    cout << f << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    FOR(i, 1, t) {
        int n; cin >> n;
        string str; cin >> str;
        solve(str, n);
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}