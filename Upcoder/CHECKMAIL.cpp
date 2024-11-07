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

vector<string> XYZ = {"@gmail.com", "@yahoo.com", "@yahoo.com.vn",
                      "@hcmup.edu.vn", "@student.hcmup.edu.vn", "@live.com",
                      "@hotmail.com", "@msn.com"};

bool check (char c) {
    return isalnum(c) || c == '_' || c == '.';
}

bool valid_abc (string str) {
    for (char c : str) if (!check(c)) return false;
    return true;
}

bool valid_xyz (string str) {
    return find(all(XYZ), str) != XYZ.end();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str;
    while (getline(cin, str)) {
        string abc = str.substr(0, str.find('@'));
        string xyz = str.substr(str.find('@') + 1);
        if (valid_abc(abc) && valid_xyz(xyz)) cout << "YES\n";
        else cout << "NO\n";
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}