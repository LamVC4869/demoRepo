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

struct fraction {
    int a, b;
    fraction () : a(0), b(1) {}
    fraction (int a, int b) : a(a), b(b) {}
    fraction (double x) {
        int tmp = int(x);
        x -= tmp*1.0;
        string t = to_string(x);
        string r = t.substr(t.find('.') + 1);
        ll under = static_cast<ll>(pow(10, r.length()));
        ll above = stoll(r);
        ll tu = tmp * under + above;
        ll k = abs(__gcd(tu, under));
        this->a = tu/k;
        this->b = under/k;
    }
    fraction operator = (fraction another) {
        this->a = another.a;
        this->b = another.b;
        return *this;
    }
    static int gcd (int a, int b) {
        int x = a, y = b;
        while (y) {
            int z = x % y;
            x = y;
            y = z;
        }
        return x;
    }
    friend ostream& operator << (ostream &os, fraction t) {
        if (t.b < 0) {
            t.b = abs(t.b);
            t.a *= -1;
        }
        int ucln = abs(t.gcd(t.a, t.b));
        os << t.a / ucln << '/' << t.b / ucln;
        return os;
    }
    double Value () {
        return 1.0*a/b;
    }
};  

double Round (double x) {
    return roundf(x*10000)/10000;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double x; cin >> x;
    int y;
    if (cin >> y) {
        fraction a = fraction(int(x), y);
        cout << a << '\n' << Round(a.Value());
    }
    else {
        bool dauTru = x < 0;
        if (dauTru) x *= -1.0;
        fraction b = fraction(x);
        if (dauTru) cout << '-';
        cout << b;
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}