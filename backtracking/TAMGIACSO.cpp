#include <iostream>
#include <vector>

using namespace std;

const int MIN = -1e9;
const int MAXN = 50;
int n, sum, ans, arr[MAXN][MAXN];
vector<int> path, result;
int dx[2] = {1, 1},
    dy[2] = {0, 1};

void init () {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> arr[i][j];
        }
    }
    ans = MIN;
    sum = 0;
}

void DFS (int x, int y) {
    sum += arr[x][y];
    path.push_back(arr[x][y]);
    if (x == n - 1 && y <= x) {
        if (ans < sum) {
            ans = sum;
            result = path;
        }
        return;
    }
    for (int i = 0; i <= 1; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX < n && newY <= newX) {
            DFS(newX, newY);
            sum -= arr[newX][newY];
            path.pop_back();
        }
    }
}

void print () {
    for (const auto& i : result) 
        cout << i << ' ';
    cout << '\n' << ans;
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    DFS(0, 0);
    print();
}