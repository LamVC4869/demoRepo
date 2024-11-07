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

int m, n, res = INT_MIN, cnt = 0;
int a[15][15];
int dx[] = {-1, 1, 0, 0},
    dy[] = {0, 0, -1, 1};

bool var (int x, int y) {
    return 0 <= x && x < m && 0 <= y && y < n && a[x][y] == 1;
}

void duHanh (int k, int x, int y);

void stop (int x, int y) {
    FOR(i, 0, 3) {
        int xx = x + dx[i], yy = y + dy[i];
        if (var(xx, yy)) {
            ++cnt;
            a[xx][yy] = 0;
            duHanh(i, xx, yy);
        }
    }
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> m >> n;
    FOR(i, 0, m - 1) {
        FOR(j, 0, n - 1) {
            char c; cin >> c;
            a[i][j] = c - '0';
        }
    }
    FOR(i, 0, m - 1) {
        FOR(j, 0, n - 1) {
            cnt = 0;
            if (a[i][j] == 1) {
                a[i][j] = 0;
                ++cnt;
                stop(i, j);
                res = max(res, cnt);
            }
        }
    }
    cout << res;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}