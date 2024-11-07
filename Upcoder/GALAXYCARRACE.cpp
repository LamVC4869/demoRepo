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
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m, fx, fy, ex, ey, res = INT_MAX;
vector<vector<char>> a;
vector<vector<bool>> visited;
bool found = false;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool var (int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m && a[x][y] != '#' && !visited[x][y];
}

void Try (int x, int y, int sum) {
    if (x == ex && y == ey) {
        found = true;
        res = min(res, sum);
        return;
    }
    FOR(i, 0, 3) {
        int xx = x + dx[i], yy = y + dy[i];
        if (var(xx, yy)) {
            visited[xx][yy] = true;
            Try(xx, yy, sum + 1);
            visited[xx][yy] = false;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    a.rz(n, vector<char>(m));
    visited.rz(n, vector<bool>(m, false));
    FOR(i, 0, n - 1) {
        FOR(j, 0, m - 1) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                fx = i;
                fy = j;
            }
            if (a[i][j] == 'B') {
                ex = i;
                ey = j;
            }
        }
    }
    visited[fx][fy] = true;
    Try(fx, fy, 1);
    if (!found) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n" << res << '\n';
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}