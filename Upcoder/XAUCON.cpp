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

const int LIMIT = 2e5 + 1;
int a[LIMIT], previous[LIMIT], idx = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 0) previous[++idx] == i;
    }
    FOR(i, 1, n) {
        if (a[i] != 0) {
            FOR(j, 1, idx) a[i] = min(a[i], abs(a[j] - i));
        }
    }
    FOR(i, 1, n) cout << a[i] << ' ';
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}