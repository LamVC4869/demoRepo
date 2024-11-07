#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void solve (int a, int b, int c) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << -1;
            }
            else {
                cout << 0;
            }
        }
        else {
            double x = c/(-1.0*b);
            cout << 1 << '\n';
            cout << fixed << setprecision(10) << x;
        }
    }
    else {
        int delta = pow(b, 2) - 4*a*c;
        if (delta < 0) {
            cout << 0;
        }
        else if (delta > 0) {
            double x1 = (-b + sqrt(delta))/(2.0*a);
            double x2 = (-b - sqrt(delta))/(2.0*a);
            if (x1 > x2) swap(x1, x2);
            cout << 2 << '\n';
            cout << fixed << setprecision(10) << x1 << '\n';
            cout << fixed << setprecision(10) << x2;
        }
        else {
            cout << 1 << '\n';
            cout << fixed << setprecision(10) << double(-b/(2.0*a));
        }
    }
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    int a, b, c;
    cin >> a >> b >> c;
    solve(a, b, c);
}