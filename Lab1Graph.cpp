#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)1e2 + 1;

struct Graph {
    int V;
    int grid[MAXN][MAXN];    
};

/*
Kiểm tra tính hợp lệ của đồ thị
*/
bool KiemTraMaTranKeHopLe (const Graph& graph) {
    for (int i = 0; i < graph.V; ++i) {
        if (graph.grid[i][i] != 0) {
            return false;
        }
    }
    return true;
}

/*
Kiểm tra xem đồ thị có vô hướng hay không
*/
bool KiemTraDoThiVoHuong (const Graph& graph) {
    for (int i = 0; i < graph.V; ++i) {
        for (int j = i + 1; j < graph.V; ++j) {
            if (graph.grid[i][j] != graph.grid[j][i]) 
                return false;
        }
    }   
    return true;
}

/*
Số cạnh của đồ thị
*/
int SoCanhCuaDoThi (const Graph& graph) {
    bool DoThiVoHuong = KiemTraDoThiVoHuong(graph);
    int result(0);
    for (int i = 0; i < graph.V; ++i) {
        for (int j = 0; j < graph.V; ++j) {
            if (DoThiVoHuong) {
                if (j > i && graph.grid[i][j] != 0) {
                    result += 1;
                }
            }
            else {
                if (graph.grid[i][j] != 0) {
                    result += 1;
                } 
            }
        }
    }
    return result;
}

/*
Số đỉnh của đồ thị
*/
int SoDinhCuaDoThi (const Graph& graph) {
    return graph.V;
}

/*
Xuất bậc của tất cả các đỉnh
*/
vector<int> BacTatCaCacDinh (const Graph& graph) {
    vector<int> vertices(graph.V + 1);
    bool DoThiVoHuong = KiemTraDoThiVoHuong(graph);
    for (int i = 0; i < graph.V; ++i) {
        int deg = (DoThiVoHuong && graph.grid[i][i] != 0) ? 2 : 0;
        if (DoThiVoHuong) {
            for (int j = 0; j < graph.V; ++j) {
                if (i != j && graph.grid[i][j] != 0) {
                    deg += 1;
                }
            }
        }
        else {
            //deg+
            int BanBacRa(0);
            for (int j = 0; j < graph.V; ++j) {
                if (graph.grid[i][j] != 0) {
                    BanBacRa += 1;
                }
            }
            //deg-
            int BanBacVao(0);
            for (int j = 0; j < graph.V; ++j) {
                if (graph.grid[j][i] != 0) {
                    BanBacVao += 1;
                }
            }
            deg = BanBacVao + BanBacRa;
        }
        vertices[i+1] = deg;
    }
    return vertices; 
}

void XuatBacTatCaCacDinh (const Graph& graph) {
    vector<int> vertices = BacTatCaCacDinh(graph);
    cout << "Bậc của tất cả các đỉnh: \n";
    for (int i = 1; i <= graph.V; ++i) {
        cout << "deg(" << i << ") = " << vertices[i] << '\n';
    }
}

/*
Danh sách các đỉnh có số bậc lớn nhất
*/
void CacDinhCoSoBacLonNhat (const Graph& graph) {
    vector<int> vertices = BacTatCaCacDinh(graph);
    int largestVertex = vertices[1];
    for (int i = 2; i <= graph.V; ++i) {
        largestVertex = max(largestVertex, vertices[i]);
    }
    cout << "Đỉnh có số bậc lớn nhất (" << largestVertex << ") là: ";
    for (int i = 1; i <= graph.V; ++i) {
        if (vertices[i] == largestVertex) {
            cout << i << ' ';
        }
    }
}

/*
Danh sách các đỉnh có số bậc nhỏ nhất
*/
void CacDinhCoSoBacNhoNhat (const Graph& graph) {
    vector<int> vertices = BacTatCaCacDinh(graph);
    int smallestVertex = vertices[1];
    for (int i = 2; i <= graph.V; ++i) {
        smallestVertex = min(smallestVertex, vertices[i]);
    }
    cout << "Đỉnh có số bậc nhỏ nhất (" << smallestVertex << ") là: ";
    for (int i = 1; i <= graph.V; ++i) {
        if (vertices[i] == smallestVertex) {
            cout << i << ' ';
        }
    }
}

/*
Danh sách các đỉnh bậc chẵn
*/
void CacDinhCoSoBacChan (const Graph& graph) {
    vector<int> vertices = BacTatCaCacDinh(graph);
    cout << "Đỉnh có số bậc chẵn là: ";
    for (int i = 1; i <= graph.V; ++i) {
        if (vertices[i] % 2 == 0) {
            cout << i << ' ';
        }
    }
}

/*
Danh sách các đỉnh bậc lẻ
*/
void CacDinhCoSoBacLe (const Graph& graph) {
    vector<int> vertices = BacTatCaCacDinh(graph);
    cout << "Đỉnh có số bậc lẻ là: ";
    for (int i = 1; i <= graph.V; ++i) {
        if (vertices[i] % 2 != 0) {
            cout << i << ' ';
        }
    }
}

/*
Danh sách các đỉnh cô lập
*/
void CacDinhCoLap (const Graph& graph) {
    vector<int> vertices = BacTatCaCacDinh(graph);
    bool found = false;
    cout << "Đỉnh cô lập là: ";
    for (int i = 1; i <= graph.V; ++i) {
        if (vertices[i] == 0) {
            found = true;
            cout << i << ' ';
        }
    }
    if (!found) cout << "Không có";
}

/*
Danh sách các đỉnh treo
*/
void CacDinhTreo (const Graph& graph) {
    vector<int> vertices = BacTatCaCacDinh(graph);
    bool found = false;
    cout << "Đỉnh treo là: ";
    for (int i = 1; i <= graph.V; ++i) {
        if (vertices[i] == 1) {
            found = true;
            cout << i << ' ';
        }
    }
    if (!found) cout << "Không có";
}

int main () {
    freopen("graph1.txt", "r", stdin);
    Graph graph;
    cin >> graph.V;
    for (int i = 0; i < graph.V; ++i) {
        for (int j = 0; j < graph.V; ++j) {
            cin >> graph.grid[i][j];
        }
    }
    if (!KiemTraMaTranKeHopLe(graph)) {
        cout << "Ma trận kề không hợp lệ!!!";
        return 0;
    }
    if (KiemTraDoThiVoHuong(graph)) {
        cout << "Đồ thị vô hướng\n";
    }
    else {
        cout << "Đồ thị có hướng\n";
    }
    cout << "Số cạnh của đồ thị: " << SoCanhCuaDoThi(graph) << '\n';
    cout << "Số đỉnh của đồ thị: " << SoDinhCuaDoThi(graph) << '\n';
    XuatBacTatCaCacDinh(graph);
    CacDinhCoSoBacLonNhat(graph);
    cout << '\n';
    CacDinhCoSoBacNhoNhat(graph);
    cout << '\n';
    CacDinhCoSoBacChan(graph);
    cout << '\n';
    CacDinhCoSoBacLe(graph);
    cout << '\n';
    CacDinhCoLap(graph);
    cout << '\n';
    CacDinhTreo(graph);
    return 0;
}