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

vector<bool> used;

void maHoa (string &str, char c, char d) {
    FOR(i, 0, str.length() - 1) {
        if (str[i] == c && !used[i]) {
            used[i] = true;
            str[i] = d;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k; cin >> n >> k;
    string str; cin >> str;
    used.rz(str.length(), false);
    if (n == 5) {
        maHoa(str, 'T', 'U');
    }
    else {
        maHoa(str, 'A', 'U');
        maHoa(str, 'T', 'A');
        maHoa(str, 'X', 'G');
        maHoa(str, 'G', 'X');
    }
    cout << str;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}