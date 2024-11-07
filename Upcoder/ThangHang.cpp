#include <bits/stdc++.h>
#define ifile freopen("input.inp", "r", stdin)
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

struct Point {
    int x, y;
    friend istream& operator >> (istream &is, Point &p) {
        is >> p.x >> p.y;
        return is;
    }
};

double distance (Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

bool cmp (Point a, Point b) {
    if (a.x > b.x) return true;
    else if (a.x == b.x && a.y > b.y) return true;
    return false;
}

bool isValid (Point a, Point b, Point c) {
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ac = distance(a, c);
    return (abs(ab + bc - ac) < 1e-6) || (abs(ab + ac - bc) < 1e-6) || (abs(bc + ac - ab) < 1e-6);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifile;
    int n, count = 0; cin >> n;
    Point arr[n];
    for (Point &i : arr) cin >> i;
    sort(arr, arr + n, cmp);
    FOR(i, 0, n - 3)
        FOR(j, i + 1, n - 2)
            FOR(k, j + 1, n - 1)
                if (isValid(arr[i], arr[j], arr[k])) count++;
    cout << count;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}