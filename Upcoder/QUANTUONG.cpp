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

int n, m, p, q, s, t, res = INT_MAX, total = 1;
bool kt = false;
int a[21][21];
bool visited[21][21];
int dx[] = {-1, 1, 1, -1},
    dy[] = {-1, -1, 1, 1};

bool var (int x, int y) {
    return 0 < x && x <= n && 0 < y && y <= n && a[x][y] == 0 && !visited[x][y];
}

void Try (int x, int y) {
    if (x == s && y == t) {
        kt = true;
        res = min(res, total);
        return;
    }
    FOR(i, 0, 3) {
        int xx = x + dx[i], yy = y + dy[i];
        if (var(xx, yy)) {
            visited[xx][yy] = true;
            total++;
            a[xx][yy] = 1;
            Try(xx, yy);
            a[xx][yy] = 0;
            total--;
            visited[xx][yy] = false;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    setup(a, 0);
    setup(visited, false);
    cin >> n >> m >> p >> q >> s >> t;
    if (m) {
        while (m--) {
            int x, y; cin >> x >> y;
            a[x][y] = 1;
        }
    }
    a[p][q] = 1;
    visited[p][q] = true;
    Try(p, q);
    cout << kt ? res : -1;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}