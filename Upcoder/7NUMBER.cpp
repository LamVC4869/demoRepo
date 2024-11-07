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

void print (int arr[], bool fail[]) {
    FOR(i, 0, 8) if (!fail[i]) printf("%d\n", arr[i]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int arr[9], sum = 0;
    bool fail[9];
    setup(fail, false);
    FOR(i, 0, 8) {
        cin >> arr[i];
        sum += arr[i];
    }
    FOR(i, 0, 8) {
        sum -= arr[i];
        fail[i] = true;
        FOR(j, i + 1, 8) {
            sum -= arr[j];
            fail[j] = true;
            if (sum == 100) {
                print(arr, fail);
                return 0;
            }
            fail[j] = false;
            sum += arr[j];
        }
        fail[i] = false;
        sum += arr[i];
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}