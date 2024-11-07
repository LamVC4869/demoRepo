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

int n, x;
int a[200001];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> x;
    map<int, int> mp;
    FOR(i, 1, n) {
        cin >> a[i];
        if (mp.find(x - a[i]) != mp.end()) {
            cout << mp[x - a[i]] << ' ' << i;
            return 0;
        }
        mp[a[i]] = i;
    }
    return cout << "IMPOSSIBLE", 0;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}