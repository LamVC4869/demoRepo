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

class Contestant {
    private:
        string id;
        int n;
        int scores[15];
    public:
        int getAC () {
            int cnt = 0;
            FOR(i, 0, n - 1) cnt += (scores[i] != -1);
            return cnt;
        }
        int getTime () {
            int total = 0;
            FOR(i, 0, n - 1) if (scores[i] != -1) total += scores[i];
            return total;
        }
        void setN (int n) {
            this->n = n;
        }
        string getID () {
            return id;
        }
        friend istream& operator >> (istream &is, Contestant &ctt) {
            is >> ctt.id;
            FOR(i, 0, ctt.n - 1) is >> ctt.scores[i];
            return is;
        }
        friend ostream& operator << (ostream &os, Contestant ctt) {
            os << ctt.id << '-' << ctt.getAC() << '-' << ctt.getTime();
            return os << '\n';
        }
        Contestant operator = (Contestant another) {
            this->setN(another.n);
            FOR(i, 0, n - 1) this->scores[i] = another.scores[i];
            return *this;
        }
        bool operator < (Contestant another) {
            if (getAC() < another.getAC()) return true;
            else if (getAC() == another.getAC() && getTime() > another.getTime()) return true;
            return false;
        }
        bool operator > (Contestant another) {
            if (getAC() > another.getAC()) return true;
            else if (getAC() == another.getAC() && getTime() < another.getTime()) return true;
            return false;
        }
        bool operator == (Contestant another) {
            return getAC() == another.getAC() && getTime() == another.getTime();
        }
        int check (Contestant another) {
            if (*this > another) return 0;
            int x = this->getAC(), y = another.getAC();
            if (*this == another && x + 1 <= n) return 1;
            if (*this < another && this->getTime() < another.getTime() && x + 1 <= n) return 1;
            if (*this < another && y + 1 <= n) return y - x + 1;
            return -1;
        }
};

char kq (Contestant a, Contestant b) {
    if (a > b) return '>';
    else if (a < b) return '<';
    return '=';
} 

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c, n; cin >> c >> n;
    Contestant ctt[c];
    FOR(i, 0, c - 1) {
        ctt[i].setN(n);
        cin >> ctt[i];
    }
    string s, t; cin >> s >> t;
    Contestant S, T;
    FOR(i, 0, c - 1) {
        if (ctt[i].getID() == s) S = ctt[i];
        if (ctt[i].getID() == t) T = ctt[i];
    }
    cout << kq(S, T) << '\n';
    cout << S.check(T);
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}