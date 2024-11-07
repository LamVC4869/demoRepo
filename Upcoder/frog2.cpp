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

const int MAX = 1e5 + 1;

int n, k, arr[MAX], dp[MAX];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    FOR(i, 0, n - 1) cin >> arr[i];
    setup(dp, INT_MAX);
    dp[0] = 0;
    FOR(i, 1, n - 1) {
        FOR(j, 1, k) {
            if (i - j >= 0) dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
        }
    }
    cout << dp[n - 1];
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}