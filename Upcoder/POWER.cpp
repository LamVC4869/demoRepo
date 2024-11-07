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

void solve (ll a, ll b, ll c) {
    if (c == 0) {
        cout << "=\n";
        return;
    }
    if (!(c % 2)) a = abs(a), b = abs(b);
    if (a > b) cout << ">\n";
    else if (a < b) cout << "<\n";
    else cout << "=\n"; 
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        ll a, b, c; cin >> a >> b >> c;
        solve(a, b, c);
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}