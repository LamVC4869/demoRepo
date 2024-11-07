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

bool isPrime (int n) {
    FOR(i, 2, sqrt(n)) if (!(n % i)) return false;
    return n > 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, cnt = 0; cin >> n;
    FOR(i, 2, n) {
        if (isPrime(i)) {
            int t = 0;
            for (int j = i; j <= n; j *= i) t += n / j;
            cnt += t;
        }
    }
    cout << cnt;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}