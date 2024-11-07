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

const int MAXN = 1e6 + 1;

int a, b, TongCacUocSo[MAXN];

void solveTongCacUocSo () {
    FOR(i, 1, MAXN - 1) {
        for (int j = i * 2; j < MAXN; j += i) {
            TongCacUocSo[j] += i;
        }
    }
}

bool LaSoDuThua (int n) {
    return TongCacUocSo[n] > n;
}

void solveTask (int a, int b) {
    int count = 0;
    FOR(i, a, b) count += LaSoDuThua(i);
    cout << count;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solveTongCacUocSo();
    int a, b; cin >> a >> b;
    return solveTask(a, b), 0;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}