#include <bits/stdc++.h>
#define ifile freopen("expression.inp", "r", stdin)
#define ofile freopen("expression.out", "w", stdout)
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
    ifile;
    ofile;
    int n, k;
    cin >> n >> k;
    ll a[n];
    FOR(i, 0, n - 1) cin >> a[i];
    ll sum = a[0];
    sort(a + 1, a + n);
    FOR(i, 1, n - k - 1) a[i] *= -1;
    FOR(i, 1, n - 1) sum += a[i];
    cout << sum;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}