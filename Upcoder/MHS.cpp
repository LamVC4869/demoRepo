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

int gcd (int a, int b) {
    while (b) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

struct PhanSo {
    int a, b;
    void rutGon () {
        int ucln = (gcd(this->a, this->b));
        //if (this->b < 0) this->b = abs(this->b), this->a *= -1;
        this->a /= ucln, this->b /= ucln;
    }
    friend istream& operator >> (istream &is, PhanSo &ps) {
        is >> ps.a >> ps.b;
        return is;
    }
    PhanSo operator + (PhanSo another) {
        this->a = this->a * another.b + this->b * another.a;
        this->b *= another.b;
        return *this;
    }
    PhanSo operator = (PhanSo another) {
        this->a = another.a;
        this->b = another.b;
        return *this;
    }
    PhanSo operator + (int n) {
        this->a = this->a + this->b * n;
        this->b *= n;
        return *this;
    }
    friend ostream& operator << (ostream &os, PhanSo ps) {
        os << ps.a << '/' << ps.b;
    }
};

struct HonSo {
    int phanNguyen;
    PhanSo ps;
    HonSo operator = (HonSo another) {
        this->phanNguyen = another.phanNguyen;
        this->ps = another.ps;
        return *this;
    }
    HonSo operator + (HonSo another) {
        this->phanNguyen += another.phanNguyen;
        this->ps = this->ps + another.ps;
        return *this;
    }
    friend istream& operator >> (istream &is, HonSo &hs) {
        is >> hs.phanNguyen >> hs.ps;
        return is;
    }
    friend ostream& operator << (ostream &os, HonSo hs) {
        os << hs.phanNguyen << ' ' << hs.ps;
        return os;
    }
    void display () {
        PhanSo tmp = this->ps;
        tmp = tmp + this->phanNguyen;
        tmp.rutGon();
        cout << '\n' << tmp;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    HonSo hs[n];
    for (auto &i : hs) cin >> i;
    HonSo t = hs[0];
    FOR(i, 1, n - 1) t = t + hs[i];
    cout << t << '\n';
    FOR(i, 0, n - 1) hs[i].display();
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}