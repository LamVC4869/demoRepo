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
        friend istream& operator >> (istream &is, Contestant &ctt) {
            is >> ctt.id;
            FOR(i, 0, ctt.n - 1) is >> ctt.scores[i];
            return is;
        }
        friend ostream& operator << (ostream &os, Contestant ctt) {
            os << ctt.id << '-' << ctt.getAC() << '-' << ctt.getTime();
            return os << '\n';
        }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c, n; cin >> c >> n;
    Contestant ctt[c];
    FOR(i, 0, c - 1) {
        ctt[i].setN(n);
        cin >> ctt[i];
        cout << ctt[i];
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}