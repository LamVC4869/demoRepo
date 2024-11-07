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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m);
    for (int i = 0; i < m; ++i) {
        vector<int> b(n);
        for (int &i : b) cin >> i;
        sort(all(b));
        a[i] = b;
    }
    sort(all(a));
    for (const vector<int>& i : a) {
        for (const int&j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}