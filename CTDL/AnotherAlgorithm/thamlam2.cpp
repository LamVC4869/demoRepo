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
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;
    ll k(LLONG_MAX), ans = 0;
    while (a.size() > 1) {
        int idx, t = k;
        FOR(i, 1, n - 1) {
            if (a[i - 1] + a[i] < t) {
                t = a[i - 1] + a[i];
                idx = i;
            }
        }
        a[idx - 1] = t;
        ans += t;
        a.erase(a.begin() + idx);
    }
    cout << ans;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}