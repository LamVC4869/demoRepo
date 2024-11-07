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

int n;
set<int> st;

int length (int n) {
    int size = 0;
    while (n) {
        ++size;
        n /= 10;
    }
    return size;
}

bool found (int n, int i) {
    while (n) {
        if (n % 10 == i) return true;
        n /= 10;
    }
    return false;
}

void backTrack (int temp) {
    if (length(temp) == n) {
        st.insert(temp);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!temp || (abs(temp % 10 - i) != 1 && !found(temp, i))) {
            backTrack(temp * 10 + i);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    backTrack(0);
    for (int i : st) cout << i << '\n';
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}