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

void solve (string &a) {
    while (a.find("  ") != string::npos) {
        size_t i = a.find("  ");
        a.replace(i, 2, " ");
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b;
    getline(cin, a);
    getline(cin, b);
    solve(a);
    solve(b);
    cout << a << ' ' << b << '\n';
    reverse(all(a));
    reverse(all(b));
    cout << a << '\n' << b << '\n';
    double t = 1.0*a.length()/b.length();
    cout << roundf(t*100)/100;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}