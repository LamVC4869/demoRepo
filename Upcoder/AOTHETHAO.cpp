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
    int n, favorite, k;
    cin >> n;
    deque<int> a(n);
    FOR(i, 0, n - 1) cin >> a[i];
    cin >> favorite >> k;
    if (find(all(a), favorite) == a.end()) {
        cout << -1;
        return 0;
    }
    deque<int> days;
    int idx = 2;
    FOR(i, 1, k) {
        int t = a[0];
        a.erase(a.begin());
        a.pb(t);
        if (t == favorite) days.pb(idx);
        idx++;
        if (idx > 8) idx = 2;
    }
    if (days.empty()) {
        cout << -1;
        return 0;
    }
    cout << days.size() << '\n';
    FOR(i, 0, days.size() - 1) cout << days[i] << ' ';
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}