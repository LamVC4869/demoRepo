#include <bits/stdc++.h>

using namespace std;

int n, m;
string str;
vector<vector<char>> a;
vector<vector<bool>> visited;
bool found = false;
queue<char> q;
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1},
    dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};

void backTrack (int x, int y) {
    if (q.empty()) {
        found = true;
        return;
    }
    for (int i = 0; i < 8; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        char z = q.front();
        if (0 <= xx && xx < n && 0 <= yy && yy < m && a[xx][yy] == z && !visited[xx][yy]) {
            visited[xx][yy] = true;
            q.pop();
            backTrack(xx, yy);
            if (found) return;
            q.push(z);
            visited[xx][yy] = false;
        }
    }
}

int main () {
    cin >> n >> m;
    a.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    map<char, int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            mp[a[i][j]]++;
        }
    }
    cin >> str;
    for (char c : str) {
        q.push(c);
        if (!mp[c]) return cout << "NO", 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c = q.front();
            if (a[i][j] == c) {
                visited[i][j] = true;
                q.pop();
                backTrack(i, j);
                if (found) {
                    return cout << "YES", 0;
                }
                q.push(c);
                visited[i][j] = false;
            }
        }
    }
    cout << "NO";
}