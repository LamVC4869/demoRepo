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

const int MAXN = 100;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, arr[MAXN], ans = -1;
    cin >> n >> m;
    FOR(i, 0, n - 1) cin >> arr[i];
    FOR(i, 0, n - 3) {
        FOR(j, i + 1, n - 2) {
            FOR(k, j + 1, n - 1) {
                int total = arr[i] + arr[j] + arr[k];
                if (total <= m) ans = max(ans, total);
            }
        }
    }
    cout << ans;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}