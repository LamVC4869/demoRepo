#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
using namespace std;

int n, m, t;
char a[51][51];
bool visited[51][51];
string k;
vector<pair<int, int>> path, res;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1},
    dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

vector<pair<int, int>> find_char(string str) {
    vector<pair<int, int>> v;
    FOR(i, 0, n - 1) {
        FOR(j, 0, m - 1) {
            if (a[i][j] == str[0]) {
                v.push_back({i, j});
            }
        }
    }
    return v;
}

bool var(int x, int y, string str, int dem) {
    return 0 <= x && x < n && 0 <= y && y < m && !visited[x][y] && a[x][y] == str[dem];
}

void Try(int x, int y, string str, string k, bool &found, int dem, int tmp) {
    if (!var(x, y, str, dem)) return;
    if (found) return;
    k += a[x][y]; // Thêm ký tự hiện tại vào chuỗi k
    if (k == str) { // Kiểm tra xem kết quả đã trùng với từ cần tìm chưa
        found = true;
        res = path;
        cout << "YES\n";
        for (auto i : res) cout << "(" << i.first + 1 << "," << i.second + 1 << ") ";
        return;
    }
    path.push_back({x, y});
    switch (tmp) {
        case 0: Try(x - 1, y - 1, str, k, found, dem + 1, tmp); break;
        case 1: Try(x - 1, y, str, k, found, dem + 1, tmp); break;
        case 2: Try(x - 1, y + 1, str, k, found, dem + 1, tmp); break;
        case 3: Try(x, y - 1, str, k, found, dem + 1, tmp); break;
        case 4: Try(x, y + 1, str, k, found, dem + 1, tmp); break;
        case 5: Try(x + 1, y - 1, str, k, found, dem + 1, tmp); break;
        case 6: Try(x + 1, y, str, k, found, dem + 1, tmp); break;
        case 7: Try(x + 1, y + 1, str, k, found, dem + 1, tmp); break;
    }
    path.pop_back();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> t;
    FOR(i, 0, n - 1)
        FOR(j, 0, m - 1) 
            cin >> a[i][j];
    FOR(z, 1, t) {
        string str;
        cin >> str;
        k = str[0];
        vector<pair<int, int>> v = find_char(str);
        bool found = false;
        for(auto i : v) {
            path.clear();
            path.push_back({i.first, i.second});
            FOR(tmp, 0, 7) Try(i.first, i.second, str, found, 1, tmp);
            if (found) break;
        }
        if (!found) cout << "NO\n";
        else cout << '\n';
    }
    return 0;
}