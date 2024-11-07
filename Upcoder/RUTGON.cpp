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

void solve (string &str) {
    int i = 0;
    while (i < str.length()) {
        while (i > 0 && str[i] == str[i + 1]) {
            str.erase(i, 2);
            --i;
        }
        while (i == 0 && str[i] == str[i + 1]) {
            str.erase(i, 2);
        }
        ++i;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str, copy;
    cin >> str;
    copy = str;
    solve(str);
    cout << (str.empty() ? "Empty String" : str);
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}