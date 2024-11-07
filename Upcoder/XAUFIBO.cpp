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

string f[36];

void init () {
    f[1] = "A", f[2] = "B";
    FOR(i, 3, 35) f[i] = f[i - 1] + f[i - 2];
}

int prevail (string a, string b) {
    int i = 0, t = b.length(), cnt = 0;
    while (i < a.length()) {
        string tmp = a.substr(i, t);
        cnt += tmp == b;
        i++;
    }
    return cnt;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int n;
    while (cin >> n) {
        string s; cin >> s;
        cout << prevail(f[n], s) << '\n';
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}