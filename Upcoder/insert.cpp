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

bool isSpecialChr (char chr) {
    return chr == '<' || chr == '>';
}

string Insert (string text) {
    int i = 0, n = text.length();
    string newText;
    FOR(j, 0, n - 1) {
        if (!isSpecialChr(text[j])) {
            newText.insert(i, 1, text[j]);
            ++i;
        }
        else {
            if (text[j] == '<') {
                --i;
                if (i < 0) i = 0;
            }
            else {
                ++i;
                if (i > int(newText.size())) i = newText.size();
            }
        }
    }
    return newText;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string text;
    getline(cin, text);
    string ans = Insert(text);
    cout << ans;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}