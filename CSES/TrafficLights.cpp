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

int x, n;
multiset<int> pos, dis;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> x >> n;
    pos.insert(0);
    pos.insert(x);
    dis.insert(x);
    FOR(i, 1, n) {
        int a; cin >> a;
        auto it = pos.upper_bound(a);
        int r = *it, l = *(--it);
        dis.erase(dis.find(r - l));
        dis.insert(r - a);
        dis.insert(a - l);
        pos.insert(a);
        cout << *dis.rbegin() << ' ';
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}