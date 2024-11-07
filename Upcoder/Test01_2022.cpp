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

struct Rectangle {
    double length, width;

    double Perimeter () {
        return 2.0 * (length + width);
    }
    friend istream& operator >> (istream &is, Rectangle &rectangle) {
        is >> rectangle.length >> rectangle.width;
        return is;
    }
    friend ostream& operator << (ostream &os, Rectangle rectangle) {
        os << rectangle.length << ',' << rectangle.width << ',' << rectangle.Perimeter();
        return os << '\n';
    }
    bool operator < (Rectangle another) {
        return this->Perimeter() < another.Perimeter();
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Rectangle *rectangle = new Rectangle [2];
    cin >> rectangle[0] >> rectangle[1];
    cout << rectangle[0] << rectangle[1];
    bool compare = rectangle[0] < rectangle[1];
    cout << (compare ? "true" : "false");
    delete [] rectangle;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}