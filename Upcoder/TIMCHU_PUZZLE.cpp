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

int n, m, t;
char a[51][51];
bool kt;

ostream& operator << (ostream &os, pair<int, int> p) {
    os << '(' << p.fi << ',' << p.se << ')';
    return os;
}

void Try (int x, int y, vector<pair<int, int>> &path, string str, int l) {
    if (str.size() == 0) {
        kt = true;
        cout << "YES\n";
        FOR(i, 0, path.size() - 1) cout << path[i] << ' ';
        cout << '\n';
        return;
    }
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    else if (a[x][y] != str[0]) return;
    else if (a[x][y] == str[0]) {
        path.pb({x + 1, y + 1});
        str.erase(0, 1);
        if (l == 0) Try(x - 1, y - 1, path, str, l);
        else if (l == 1) Try(x - 1, y, path, str, l);
        else if (l == 2) Try(x - 1, y + 1, path, str, l);
        else if (l == 3) Try(x, y - 1, path, str, l);
        else if (l == 4) Try(x, y + 1, path, str, l);
        else if (l == 5) Try(x + 1, y - 1, path, str, l);
        else if (l == 6) Try(x + 1, y, path, str, l);
        else Try(x + 1, y + 1, path, str, l);
        path.pob();
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> t;
    FOR(i, 0, n - 1) {
        FOR(j, 0, m - 1) {
            cin >> a[i][j];
        }
    }
    while (t--) {
        string str; cin >> str;
        kt = false;
        FOR(i, 0, n - 1) {
            FOR(j, 0, m - 1) {
                if (a[i][j] == str[0]) {
                    vector<pair<int, int>> path;
                    FOR(l, 0, 7) Try(i, j, path, str, l);
                }
            }
        }
        if (!kt) cout << "NO\n";
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}