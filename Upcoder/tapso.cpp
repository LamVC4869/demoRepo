#include <bits/stdc++.h>
#define ifile freopen("NUMSET.INP", "r", stdin)
#define ofile freopen("NUMSET.OUT", "w", stdout)
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

int cnt = 0;
set<int> st;
void Try (int k, string str) {
    for (int i = 0; i < str.length() && (i + k <= str.length()); ++i) {
        string tmp = str;
        tmp.erase(i, k);
        int t = stoi(tmp);
        st.insert(t);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifile;
    ofile;
    string n; cin >> n;
    while (n[0] == '0') n.erase(n.begin());
    int len = n.length();
    st.insert(stoi(n));
    FOR(i, 1, len - 1) Try(i, n);
    for (int i : st) cnt += i % 3 == 0;
    cout << cnt;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}