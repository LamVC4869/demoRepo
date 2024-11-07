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

struct Fraction {
    ll x, y;
    Fraction (ll x = 0, ll y = 1) : x(x), y(y) {}
    static ll gcd (ll x, ll y) {
        ll a = x, b = y;
        while (b) {
            ll temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    void solveFraction () {
        ll ucln = abs(gcd(x, y));
        if (y < 0) x *= -1, y = abs(y);
        x /= ucln, y /= ucln;
    }
    friend istream& operator >> (istream &is, Fraction &fraction) {
        char chr;
        is >> fraction.x >> chr >> fraction.y;
        return is;
    }
    friend ostream& operator << (ostream &os, Fraction fraction) {
        if (fraction.x == 0) return os << "0\n";
        if (fraction.y == 1) return os << fraction.x << '\n';
        os << fraction.x << '/' << fraction.y;
        return os << '\n';
    }
    Fraction Pow (ll n) {
        this->solveFraction();
        if (n == 0) {
            return {1, 1};
        }
        Fraction newFraction (this->x, this->y);
        if (n < 0) {
            swap(newFraction.x, newFraction.y);
            n *= -1;
        }
        newFraction.solveFraction();
        newFraction.x = pow(newFraction.x, n);
        newFraction.y = pow(newFraction.y, n);
        newFraction.solveFraction();
        return newFraction;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vector<Fraction> Array(n);
    vector<ll> exponential(n);
    for (int i = 0; i < n; ++i) {
        cin >> Array[i] >> exponential[i];
        Array[i] = Array[i].Pow(exponential[i]);
        cout << Array[i];
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}