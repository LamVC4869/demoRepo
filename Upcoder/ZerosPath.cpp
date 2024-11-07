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

int dp[1001][1001], 
    dp2[1001][1001], 
    dp5[1001][1001];

int countX (int n, int x) {
    int cnt = 0;
    while (n % x == 0) {
        cnt++;
        n /= x;
    }
    return cnt;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, count = 0;
    int dem = 0; //dem = count of 0
    cin >> n >> m;
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> dp[i][j];
            if (!dp[i][j]) dem = 1;
        }
    }
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (!dp[i][j]) {
                if (i == 1) {
                    dp2[i][j] = dp2[i][j - 1] + 1;
                    dp5[i][j] = dp5[i][j - 1] + 1;
                }
                else {
                    if (j == 1) {
                        dp2[i][j] = dp2[i - 1][j] + 1;
                        dp5[i][j] = dp5[i - 1][j] + 1;
                    }
                    else {
                        dp2[i][j] = min(dp2[i][j - 1], dp2[i - 1][j]) + 1;
                        dp5[i][j] = min(dp5[i][j - 1], dp5[i - 1][j]) + 1;
                    }
                }
            }
            else {
                if (i == 1) {
                    dp2[i][j] = countX(dp[i][j], 2) + dp2[i][j - 1];
                    dp5[i][j] = countX(dp[i][j], 5) + dp5[i][j - 1];
                }
                else {
                    if (j == 1) {
                        dp2[i][j] = countX(dp[i][j], 2) + dp2[i - 1][j];
                        dp5[i][j] = countX(dp[i][j], 5) + dp5[i - 1][j];
                    }
                    else {
                        dp2[i][j] = countX(dp[i][j], 2) + min(dp2[i][j - 1], dp2[i - 1][j]);
                        dp5[i][j] = countX(dp[i][j], 5) + min(dp5[i][j - 1], dp5[i - 1][j]);
                    }
                }
            }
        }
    }
    int res = min(dp2[n][m], dp5[n][m]);
    cout << (dem && res > 1 ? 1 : res);
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}