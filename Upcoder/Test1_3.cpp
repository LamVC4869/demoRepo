#include <iostream>
#define ll long long

using namespace std;

bool solve (ll n, ll m) {
    if (m < n) return false;
    if (m & 1 || n & 1) return false;
    ll a = (m - n) >> 1;
    if (n < (a << 1)) return false;
    ll b = (n - (a << 1)) >> 1;
    cout << a << ' ' << b;
    return true;
}

signed main () {
    cin.tie(NULL) -> sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    if (!solve(n, m)) return cout << "IMPOSSIBLE", 0;
}