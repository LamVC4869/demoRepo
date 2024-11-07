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

ll calc (ll x) {
    if (x < 10) return x;
    ll sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return calc(sum);
}

ll digitRoot (ll x) {
    if (x < 10) return x;
    return calc(x);
}

ll repeat (string x, ll k) {
    ll sum = 0;
    for (char c : x) sum += c - '0';
    sum *= k;
    return sum;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string x;
    int k;
    cin >> x >> k;
    cout << digitRoot(repeat(x, k));
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}