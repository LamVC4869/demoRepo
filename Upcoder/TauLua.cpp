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

vector<pair<char, char>> v;

bool kt (queue<string> &prev, queue<string> &curr) {
    queue<string> final, res;
    stack<string> carry;
    final = curr;
    while (!final.empty()) {
        string s = final.front();
        final.pop();
        if (!prev.empty()) {
            if (prev.front() == s) {
                v.pb({'A', 'C'});
                res.push(s);
                prev.pop();
            }
            else {
                if (!carry.empty() && carry.top() == s) {
                    v.pb({'B', 'C'});
                    res.push(s);
                    carry.pop();
                }
                else {
                    while (!prev.empty() && prev.front() != s) {
                        v.pb({'A', 'B'});
                        carry.push(prev.front());
                        prev.pop();
                    }
                    if (prev.empty()) return false;
                    else {
                        v.pb({'A', 'C'});
                        res.push(s);
                        prev.pop();
                    }
                }
            }
        }
        else {
            if (!carry.empty() && carry.top() == s) {
                v.pb({'B', 'C'});
                res.push(s);
                carry.pop();
            }
            else return false;
        }
    }
    while (!curr.empty()) {
        if (curr.front() != res.front()) return false;
        curr.pop();
        res.pop();
    }
    return true;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b; cin >> a >> b;
    if (a.length() != b.length()) {
        cout << "No";
        return 0;
    }
    for (char &c : a) if (c == '-') c = ' ';
    for (char &c : b) if (c == '-') c = ' ';
    queue<string> prev, curr;
    stringstream ss1(a), ss2(b);
    while (ss1 >> a) prev.push(a);
    while (ss2 >> b) curr.push(b);
    if(kt(prev, curr)) {
        cout << "Yes\n";
        FOR(i, 0, v.size() - 1) cout << i + 1 << " : " << v[i].fi << " -> " << v[i].se << '\n';
    }
    else cout << "No";
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}