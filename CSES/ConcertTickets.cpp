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

int n, m;
multiset<ll> h;

void search (ll x) {
    auto it = h.upper_bound(x);
    if (it == h.begin()) {
        cout << -1 << '\n';
    }
    else {
        --it;
        cout << *it << '\n';
        h.erase(it);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    FOR(i, 1, n) {
        ll x; cin >> x;
        h.insert(x);
    }
    FOR(i, 1, m) {
        ll t; cin >> t;
        search(t);
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}