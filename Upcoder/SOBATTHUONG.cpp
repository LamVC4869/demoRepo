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

const int LIMIT = 1e6 + 1;
int notPrime[LIMIT];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    notPrime[0] = notPrime[1] = 1;
    FOR(i, 2, LIMIT) {
        if (!notPrime[i]) {
            for (int j = i; j < LIMIT; j += i) {
                notPrime[j] = i;
            }
        }
    }
    int a, b; cin >> a >> b;
    FOR(i, a, b) if (notPrime[i] != i && notPrime[i] > sqrt(i)) cout << i << '\n';
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}