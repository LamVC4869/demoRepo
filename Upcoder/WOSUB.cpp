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

const int MAXN = 1e5 + 1;
int n, s, a[MAXN], b[MAXN], ans = INT_MIN;
bool kt = false;

void init () {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    cin >> s;
    b[1] = a[1];
    FOR(i, 2, n) b[i] = b[i - 1] + a[i];
}

int search (int a[], int n, int x) {
    FOR(i, 1, n) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

void solve () {
    FOR(i, 1, n) {
        if (b[i] >= s) {
            int ii = search(b, n, b[i] - s);
            if (ii != -1) {
                ans = max(ans, i - ii);
                kt = true;
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    solve();
    kt ? cout << ans : cout << -1;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}