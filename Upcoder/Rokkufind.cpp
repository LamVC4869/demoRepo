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

ll gcd (ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll Integer (string str) {
    ll k = 0;
    for (char c : str) {
        if (c == '.') break;
        k = k*10 + int(c - '0');
    }
    return k;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str; cin >> str;
    bool negative = (str[0] == '-');
    if (negative) str.erase(0, 1);
    ll idx = Integer(str);
    str = str.substr(str.find('(') + 1);
    str.pob();
    ll t = stoll(str), size = str.size();
    ll mau = 0;
    FOR(i, 1, size) mau = mau*10 + 9;
    ll tu = t + idx*mau;
    ll ucln = gcd(tu, mau);
    tu /= ucln, mau /= ucln;
    if (negative) cout << '-';
    if (tu % mau == 0) cout << tu / mau << '\n';
    else cout << tu << '/' << mau << '\n';
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}