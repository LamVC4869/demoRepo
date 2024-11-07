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

vector<vector<int>> arr;

int sum (int x) {
    int total = 0;
    while (x) {
        total += x % 10;
        x /= 10;
    }
    return total;
}

int val (vector<int> v) {
    int total = 0;
    for (int i : v) total += sum(i);
    return total;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int odd = 1, even = 2;
    FOR(i, 1, 10) {
        vector<int> v;
        if (i & 1) {
            FOR(j, 1, i) {
                v.pb(odd);
                odd += 2;
            }
        }
        else {
            FOR(j, 1, i) {
                v.pb(even);
                even += 2;
            }
        }
        arr.pb(v);
    }
    int m; cin >> m;
    FOR(i, 0, arr.size() - 1) {
        if (find(all(arr[i]), m) != arr[i].end()) {
            return cout << val(arr[i]), 0;
        }
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}