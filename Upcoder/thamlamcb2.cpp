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

int gcd(int a, int b) {
    while (b) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

struct fraction {
    int a, b;
    void rutGon() {
        int ucln = gcd(this->a, this->b);
        this->a /= ucln;
        this->b /= ucln;
    }
    friend ostream& operator<<(ostream &os, fraction frac) {
        os << frac.a << '/' << frac.b;
        return os;
    }
};

fraction make_fraction(int a, int b) {
    fraction f;
    f.a = a;
    f.b = b;
    f.rutGon();
    return f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int p, q; cin >> p >> q;
    if (p == q) {
        cout << "1/1";
        return 0;
    }
    vector<fraction> v;
    int k = gcd(p, q);
    p /= k, q /= k;
    while (p) {
        int x = (q + p - 1)/p;
        v.pb(make_fraction(1, x));
        p = p*x - q, q *= x;
        k = gcd(p, q);
        p /= k, q /= k;
    }
    FOR(i, 0, v.size() - 1) {
        cout << v[i];
        if (i < v.size() - 1) cout << " + ";
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}