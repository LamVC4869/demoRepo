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

const int MAXN = 2e5 + 1;
int n;
int a[MAXN], b[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    stack<int> myStack;
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    myStack.push(1);
    FOR(i, 2, n) {
        while (!myStack.empty() && a[myStack.top()] >= a[i]) myStack.pop();
        if (!myStack.empty() && a[myStack.top()] < a[i]) {
            b[i] = myStack.top();
        }
        else {
            b[i] = 0;
        }
        myStack.push(i);
    }
    FOR(i, 1, n) cout << b[i] << ' ';
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}