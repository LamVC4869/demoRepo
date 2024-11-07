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

int n;
double result = INT_MIN*1.0;
string str;
vector<vector<char>> a;
int dx[] = {1, 1},
    dy[] = {0, 1};

double solve (double a, char Operator, char b) {
    double idx = b - '0';
    if (Operator == '+') a += idx;
    else if (Operator == '-') a -= idx;
    else if (Operator == '*') a *= idx;
    else if (Operator == '/') a /= idx;
    return a;
}

double value (string str) {
    double total = str[0] - '0';
    for (int i = 1; i < str.length(); i += 2) {
        total = solve(total, str[i], str[i + 1]);
    }
    return total;
}

bool var (int x, int y) {
    return x < n && y <= x;
}

void Try (int x, int y, string k) {
    if (x == n - 1 && y <= x) {
        double val = value(k);
        if (val > result) {
            result = val;
            str = k;
        }
        return;
    }
    FOR(i, 0, 1) {
        int xx = x + dx[i], yy = y + dy[i];
        if (var(xx, yy)) {
            k.pb(a[xx][yy]);
            Try(xx, yy, k);
            k.pob();
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    a.rz(n, vector<char>(n));
    FOR(i, 0, n - 1) {
        FOR(j, 0, i) {
            cin >> a[i][j];
        }
    }
    string k;
    k.pb(a[0][0]);
    Try(0, 0, k);
    cout << str << '\n' << static_cast<double>(result);
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}