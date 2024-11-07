#include <bits/stdc++.h>
#define ifile freopen("PHOMAI.INP", "r", stdin)
#define ofile freopen("PHOMAI.OUT", "w", stdout)
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

int gcd (ll a, ll b) {
    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void solve (ll a, ll b) {
    if (a == b) {
        cout << 0;
        return;
    }
    int k = gcd(a, b);
    a /= k, b /= k;
    int cnt = 0;
    while (a % 2 == 0) {
        ++cnt;
        a /= 2;
    }
    while (a % 3 == 0) {
        ++cnt;
        a /= 3;
    }
    while (a % 5 == 0) {
        ++cnt;
        a /= 5;
    }
    while (b % 2 == 0) {
        ++cnt;
        b /= 2;
    }
    while (b % 3 == 0) {
        ++cnt;
        b /= 3;
    }
    while (b % 5 == 0) {
        ++cnt;
        b /= 5;
    }
    cout << (a == b ? cnt : -1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifile;
    ofile;
    ll a, b; cin >> a >> b;
    solve(a, b);
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}