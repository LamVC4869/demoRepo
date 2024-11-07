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

ull f[21];

void init () {
    f[1] = 1;
    FOR(i, 2, 20) f[i] = i * f[i - 1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    string str; cin >> str;
    int s = str.length();
    if (s <= 19) {
        FOR(i, 1, 20) {
            string tmp = to_string(f[i]);
            if (tmp == str) return cout << i, 0;
        }
    }
    int i = 21;
    double t = log10(f[20]);
    while (int(t + 1) < s) {
        t += log10(i);
        i++;
    }
    cout << i - 1;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}