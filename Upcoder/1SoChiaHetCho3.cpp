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
    ll n, res = INT_MIN; cin >> n;
    string str = to_string(n);
    FOR(i, 0, str.length() - 1) {
        string tmp = str;
        char c = tmp[i];
        FOR(j, 0, 9) {
            tmp[i] = char(j + '0');
            ll k = stoll(tmp);
            if (k % 3 == 0 && tmp[i] != c) res = max(res, k);
        }
    }
    cout << res;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}