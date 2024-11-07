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

int result (vector<int> a) {
    int l = 0, r = a.size() - 1, l_max = 0, r_max = 0, total = 0;
    while (l < r) {
        l_max = max(l_max, a[l]);
        r_max = max(r_max, a[r]);
        if (l_max < r_max) {
            total += l_max - a[l];
            l++;
        }
        else {
            total += r_max - a[r];
            r--;
        }
    }
    return total;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> height;
    int x;
    while (cin >> x) height.pb(x);
    cout << result(height);
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}