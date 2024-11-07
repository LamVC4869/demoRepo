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

const int MAXN = 5e3 + 1;
int arr[MAXN], dp[MAXN], ans(0);

int gcd (int x, int y) {
    while (y) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    FOR(i, 0, n - 1) cin >> arr[i], dp[i] = 1;
    sort(arr, arr + n);
    FOR(i, 1, n - 1) {
        FOR(j, 0, i - 1) {
            if (gcd(arr[i], arr[j]) == 1) 
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}