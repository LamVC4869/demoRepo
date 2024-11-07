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

vector<string> Gray (int n) {
    if (n == 1) return {"0", "1"};
    vector<string> t = Gray(n - 1), l1, l2;
    FOR(i, 0, t.size() - 1) l1.pb("0" + t[i]);
    FOD(i, t.size() - 1, 0) l2.pb("1" + t[i]);
    l1.insert(l1.end(), all(l2));
    return l1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    vector<string> res = Gray(n);
    for (string i : res) cout << i << '\n';
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}