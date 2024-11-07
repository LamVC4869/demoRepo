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

vector<int> arr, dp;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    arr.rz(n + 1);
    dp.rz(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j >= 1; --j) {
            if (arr[i] > arr[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    cout << *max_element(all(dp));
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}