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
int n, k, a[MAXN];
deque<int> dq;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    FOR(i, 0, n - 1) cin >> a[i];
    FOR(i, 0, n - 1) {
        if (!dq.empty() && dq.front() == i - k) dq.pof();
        while (!dq.empty() && a[dq.back()] <= a[i]) dq.pob();
        dq.pb(i);
        if (i >= k - 1) cout << a[dq.front()] << ' ';
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}