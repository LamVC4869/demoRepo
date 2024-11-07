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

int n, k, s, res;
void backTrack (int i, int cnt, int sum) {
    if (cnt == k) {
        if (sum == s) {
            ++res;
        }
        return;
    }
    if (cnt >= k || sum > s || i > n) return;
    if (i < n) backTrack(i + 1, cnt + 1, sum + i);
    backTrack(i + 1, cnt, sum);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k >> s;
    backTrack(1, 0, 0);
    cout << res;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}