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

bool SequentialSearch (vector<int> arr, int x) {
    int key = -1, value = INT_MIN;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > value && arr[i] <= x) {
            key = i;
            value = arr[i];
        }
    }
    if (key != -1) return cout << key, true;
    return false;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int x, element;
    cin >> x;
    vector<int> arr;
    while (cin >> element) {
        arr.pb(element);
    }
    if (!SequentialSearch(arr, x)) return cout << -1, 0;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}