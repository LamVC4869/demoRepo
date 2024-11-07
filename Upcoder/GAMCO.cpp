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

int r, c, sx, sy, ex, ey, path = INT_MAX, cnt = 0;
char a[100][100];
bool visited[100][100];
int dx[] = {-1, 0, 1, 0},
    dy[] = {0, -1, 0, 1};

bool var (int x, int y) {
    return 0 <= x && x < r && 0 <= y && y < c && !visited[x][y] && a[x][y] != '*';
}

void dfs (int x, int y) {
    if (x == ex && y == ey) {
        path = min(path, cnt);
        return;
    }
    FOR(i, 0, 3) {
        int xx = x + dx[i], yy = y + dy[i];
        if (var(xx, yy)) {
            visited[xx][yy] = true;
            cnt++;
            dfs(xx, yy);
            cnt--;
            visited[xx][yy] = false;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    setup(visited, false);
    cin >> r >> c;
    FOR(i, 0, r - 1) {
        FOR(j, 0, c - 1) {
            cin >> a[i][j];
            if (a[i][j] == 'C') {
                sx = i;
                sy = j;
            }
            if (a[i][j] == 'B') {
                ex = i;
                ey = j;
            }
        }
    }
    visited[sx][sy] = true;
    dfs(sx, sy);
    cout << path;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}