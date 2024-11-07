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
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int a[51][51];

double Det(int a[][51], int n) {
    if (n == 1) {
        return a[0][0];
    }
    if (n == 2) {
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    }

    double det = 0;
    for (int i = 0; i < n; i++) {
        int sign = (i % 2 == 0) ? 1 : -1;
        double subdet = Det(a + 1, n - 1);
        det += sign * a[0][i] * subdet;
        for (int j = 0; j < n - 1; j++) {
            a[j][i] = a[j + 1][i];
        }
    }

    return det;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    FOR(i, 0, n - 1) 
        FOR(j, 0, n - 1) 
            cin >> a[i][j];
    bool khaNghich = Det(a, n) != 0;
    cout << (khaNghich ? "Yes" : "No") << '\n';
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}