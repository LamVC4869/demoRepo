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

bool scp (ll n) {
    return int(sqrt(n)) == sqrt(n);
}

bool isvalid (ll a, ll b) {
    if (a == b || a < 3 || b < 3) return false;
    ll k = max(a, b);
    if (a == k) swap(a, b);
    if (scp(k*k - a*a) || scp(k*k + a*a)) return true;
    return false;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    FOR(i, 1, n) {
        ll a, b; cin >> a >> b;
        cout << isvalid(a, b) << '\n';
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}