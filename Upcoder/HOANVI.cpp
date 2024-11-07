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

string str;

void Try (int n) {
    if (str.size() == n) {
        FOR(i, 0, n - 1) {
            cout << str[i];
            if (i < n - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    FOR(i, 1, n) {
        if (str.find(i + '0') == -1) {
            str.pb(i + '0');
            Try(n);
            str.pob();
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    Try(n);
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}