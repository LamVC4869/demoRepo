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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> v1, v2;
    int n, m, result = INT_MIN;
    cin >> n >> m;
    FOR(i, 0, n - 1) {
        int x; cin >> x;
        v1.pb(x);
    }
    FOR(i, 0, m - 1) {
        int x; cin >> x;
        v2.pb(x);
    }
    sort(all(v2));
    FOR(i, 0, v1.size() - 1) {
        int t = INT_MAX;
        auto it = lower_bound(all(v2), v1[i]);
        if (it != v2.end()) t = min(t, abs(*it - v1[i]));
        if (it != v2.begin()) t = min(t, abs(*(it - 1) - v1[i]));
        result = max(result, t);
    }
    cout << result << '\n';
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}