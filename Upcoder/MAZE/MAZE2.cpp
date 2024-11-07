#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> a;
vector<vector<bool>> visited;
vector<string> paths;
string str;
char Move[] = {'X', 'P', 'T', 'L'};
int dx[] = {1, 0, 0, -1},
    dy[] = {0, 1, -1, 0};

bool check_var (int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n && a[x][y] != 0 && !visited[x][y];
}

void backTrack (int x, int y) {
    if (x == n - 1 && y == n - 1) {
        paths.push_back(str);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (check_var(xx, yy)) {
            str.push_back(Move[i]);
            visited[xx][yy] = true;
            backTrack(xx, yy);
            visited[xx][yy] = false;
            str.pop_back();
        }
    }
}

int main () {
    cin >> n;
    a.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    if (a[n - 1][n - 1] == 0 || a[0][0] == 0) {
        cout << -1;
        return 0;
    }
    visited[0][0] = true;
    backTrack(0, 0);
    if (paths.empty()) cout << -1;
    else {
        for (string i : paths) cout << i << '\n';
    }
    return 0;
}