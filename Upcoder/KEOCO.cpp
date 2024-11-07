#include <bits/stdc++.h>
#define ifile freopen("KEOCO.inp", "r", stdin)
#define ofile freopen("KEOCO.out", "w", stdout)
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

int n, a[10], carry = INT_MAX;
vector<int> nhom1, nhom2, res1, res2;

int total (vector<int> v) {
    int t = 0;
    FOR(i, 0, v.size() - 1) t += v[i];
    return t;
}

void Try (int x) {
    if (x == n) {
        int dis = abs((int)nhom1.size() - (int)nhom2.size());
        if (dis <= 1) {
            int t1 = total(nhom1), t2 = total(nhom2), d = abs(t1 - t2);
            if (d < carry) {
                carry = d;
                res1 = nhom1;
                res2 = nhom2;
            }
        }
        return;
    }
    nhom1.pb(a[x]);
    Try(x + 1);
    nhom1.pob();
    nhom2.pb(a[x]);
    Try(x + 1);
    nhom2.pob();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifile, ofile;
    cin >> n;
    FOR(i, 0, n - 1) cin >> a[i];
    Try(0);
    int x = total(res1), y = total(res2);
    if (x > y) swap(x, y);
    cout << x << ' ' << y;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}