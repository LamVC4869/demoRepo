#include <bits/stdc++.h>
#define ifile freopen("MAXMINTT.inp", "r", stdin)
#define ofile freopen("MAXMINTT.out", "w", stdout)
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

struct Arr {
    int x, y;
    bool operator < (Arr another) {
        return x < another.x;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifile;
    ofile;
    int n, t; cin >> n;
    Arr a[n];
    FOR(i, 0, n - 1) {
        cin >> a[i].x;
        a[i].y = i;
    }
    sort(a, a + n);
    cin >> t;
    int h, k, i, j;
    while (t--) {
        cin >> h >> k;
        for (i = 0; a[i].y < h - 1 || a[i].y > k - 1; ++i);
        for (j = n - 1; a[j].y < h - 1 || a[j].y > k - 1; --j);
        cout << a[j].x << ' ' << a[i].x << '\n';
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}