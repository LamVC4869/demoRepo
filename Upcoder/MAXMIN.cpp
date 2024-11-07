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

vector<int> a;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x = INT_MIN, y = INT_MAX; 
    cin >> n;
    a.rz(n);
    FOR(i, 0, n - 1) {
        cin >> a[i];
        x = max(x, a[i]);
        y = min(y, a[i]);
    }
    int t = y;
    FOR(i, 0, n - 1) {
        if (a[i] != x) t = max(t, a[i]);
    }
    if (t == y || x == y) return cout << 0, 0;
    cout << t - y;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}