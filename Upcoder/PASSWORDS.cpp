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
    int n, k; cin >> n >> k;
    string str[n], pass;
    for (string &i : str) cin >> i;
    cin >> pass;
    int L = pass.length(), s1 = 0, s2 = 0;
    FOR(i, 0, n - 1) {
        if (str[i].length() < L) s1++;
        if (str[i].length() > L) s2++;
    }
    int t1 = s1/k*5;
    cout << s1 + t1 + 1 << ' ';
    int spot = n - s2 - 1;
    int t2 = spot/k*5;
    cout << t2 + n - s2;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}