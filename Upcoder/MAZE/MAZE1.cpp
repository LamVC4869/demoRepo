#include <iostream>
#include <vector>

using namespace std;

int n;
string str, Move[] = {"X", "P"};
int dx[] = {1, 0},
    dy[] = {0, 1};

bool check_var (int x, int y, vector<vector<int>> a) {
    return x < n && y < n && a[x][y] != 0;
}

void backTrack (int x, int y, vector<string> &paths, vector<vector<int>> a) {
    if (x == n - 1 && y == n - 1) {
        paths.push_back(str);
        return;
    }
    for (int i = 0; i < 2; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (check_var(xx, yy, a)) {
            str += Move[i];
            backTrack(xx, yy, paths, a);
            str.pop_back();
        }
    }
}

int main () {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> a;
        a.resize(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> a[i][j];
        if (a[n - 1][n - 1] == 0 || a[0][0] == 0) {
            cout << -1 << '\n';
            continue;
        }
        vector<string> paths;
        backTrack(0, 0, paths, a);
        if (paths.empty()) cout << -1 << '\n';
        else {
            for (string i : paths) cout << i << '\n';
        }
    }
}