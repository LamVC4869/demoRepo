#include <iostream>
#include <vector>

using namespace std;

int grid[16][16];
int maxOil(0);
vector<pair<int, int>> path, pathTemp = {{1, 1}};
int deltaX[] = {1, 0};
int deltaY[] = {0, 1};

void DFS (int x, int y, int M, int N, int Oil) {
    if (x == M && y == N) {
        if (Oil > maxOil) {
            path = pathTemp;
            maxOil = Oil;
        }
        return;
    }
    if (x + 1 <= M) {
        pathTemp.push_back({x + 1, y});
        DFS(x + 1, y, M, N, Oil + grid[x + 1][y]);
        pathTemp.pop_back();
    }
    if (y + 1 <= N) {
        pathTemp.push_back({x, y + 1});
        DFS(x, y + 1, M, N, Oil + grid[x][y + 1]);
        pathTemp.pop_back();
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M, N;
    cin >> M >> N;
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> grid[i][j];
        }
    }
    DFS(1, 1, M, N, grid[1][1]);
    cout << maxOil << '\n';
    for (const auto& element : path) {
        cout << element.first << ' ' << element.second << '\n';
    }
}