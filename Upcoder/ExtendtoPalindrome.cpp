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

const int limit = 1e5;
int LPS[limit];

int lps (string a, string b) {
    int i = 1, j = 0, n = a.size();
    LPS[0] = 0;
    while (i < n) {
        if (a[i] == b[j]) {
            ++j;
            LPS[i] = j;
            ++i;
        }
        else if (j > 0) j = LPS[j - 1];
        else {
            LPS[i] = 0;
            ++i;
        }
    }
    return LPS[i - 1];
}

void kmp (string s1) {
    string s2 = s1;
    reverse(all(s2));
    if (s1 == s2) cout << s1 << '\n';
    else {
        int p = lps(s1, s2);
        cout << s1;
        FOR(i, p, s1.size() - 1) cout << s2[i];
        cout << '\n';
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s1;
    while (cin >> s1) kmp(s1);
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}   