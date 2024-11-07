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

const int MAXN = 1e6;
int n, arr[MAXN];

int result (int arr[], int n) {
    int x = arr[0], y = arr[1], z = arr[2], t = x + y - z;
    FOR(i, 3, n - 1) {
        int k = max(x, max(y, z));
        if (x == k) x = k;
        else if (y == k) swap(x, y);
        else if (z == k) swap(x, z);
        y = min(x, max(y, z));
        z = arr[i];
        t = max(t, x + y - z);
    }
    return t;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    FOR(i, 0, n - 1) cin >> arr[i];
    int ans = result(arr, n);
    cout << ans;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}