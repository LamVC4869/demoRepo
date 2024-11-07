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

ull mul (ull x, ull y, ull m) {
    ull total = 0;
    x %= m;
    while (y) {
        if (y & 1)
            total = (total + x) % m;
        x = (x << 1) % m;
        y = y >> 1;
    }
    return total;
}

ull power (ull x, ull n, ull m) {
    ull k = 1;
    x %= m;
    while (n) {
        if (n & 1) k = mul(k, x, m);
        x = mul(x, x, m);
        n = n >> 1;
    }
    return k;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ull a, b, n, m;
    cin >> a >> b >> n >> m;
    ull x1 = power(a, n, m), x2 = power(b, n, m);
    cout << (x1 + x2) % m;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}