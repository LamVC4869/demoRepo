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

void solve (ll n) {
    int i, cnt = 0, l = sqrt(n);
    if (n % 2 == 0) i = 2;
    else for (i = 3; i <= l && n % i != 0; i += 2) {}
    ll j = n;
    while (j > 1) {
        if (j % i != 0) {
            cout << "NO\b";
            return;
        }
        ++cnt;
        j /= i;
    }
    if (cnt <= 1) cout << "NO\n";
    else cout << "YES " << i << '^' << cnt << '=' << n << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    ll n;
    FOR(i, 1, t) {
        cin >> n;
        solve(n);
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}