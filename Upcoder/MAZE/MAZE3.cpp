#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int n, m;
char a[5][5];
bool visited[5][5];
string s, str;
bool found = false;
int dx[] = {1, 0, 0, -1},
    dy[] = {0, 1, -1, 0};

bool check_var (int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m && !visited[x][y];
}

void backTrack (int x, int y) {
    if (s == str) {
        found = true;
        return;
    }
    if (found) return;
    if (str.length() >= s.length()) return;
    for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (check_var(xx, yy)) {
            visited[xx][yy] = true;
            str.push_back(a[xx][yy]);
            backTrack(xx, yy);
            str.pop_back();
            visited[xx][yy] = false;
        }
    }
}

int main () {
    cin >> n >> m;
    map<char, int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            mp[a[i][j]]++;
        }
    }
    cin >> s;
    for (char c : s) {
        if (mp[c] == 0) {
            cout << "NO";
            return 0;
        }
    }
    str.push_back(s[0]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == s[0]) {
                memset(visited, false, sizeof(visited));
                visited[i][j] = true;
                backTrack(i, j);
                if (found) return cout << "YES", 0;
            }
        }
    }
    if (!found) return cout << "NO", 0;
}