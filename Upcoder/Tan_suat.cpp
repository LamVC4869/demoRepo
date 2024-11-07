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

void MaxDisplay (string str) {
    map<string, int> mp;
    int cnt = -1;
    string res;
    stringstream ss(str);
    while (ss >> str) mp[str]++;
    for (auto i : mp) {
        if (i.se > cnt) {
            cnt = i.se;
            res = i.fi;
        }
    }
    cout << res << ' ' << cnt;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str;
    getline(cin, str);
    MaxDisplay(str);
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}