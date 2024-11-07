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

int distanceReview (vector<int> arr, int x) {
    int distance = INT_MAX;
    for (int i = 0; i < arr.size(); ++i) {
        distance = min(abs(x - arr[i]), distance);
    }
    return distance;
}

bool SequentialSearch (vector<int> arr, int x, int y) {
    int distance = distanceReview(arr, x);
    if (distance <= y) {
        for (int i = 0; i < arr.size(); ++i) {
            if (abs(x - arr[i]) == distance) {
                return cout << i, true;
            }
        }
    }
    return false;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x, y, digit;
    cin >> n >> x >> y;
    vector<int> arr(n);
    for (int &i : arr) cin >> i;
    if (!SequentialSearch(arr, x, y)) return cout << -1, 0;
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}