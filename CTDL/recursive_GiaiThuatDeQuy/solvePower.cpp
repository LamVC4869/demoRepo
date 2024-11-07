#include <iostream>

using namespace std;

long long Power (int a, int b) {
    if (b == 0) return 1;
    return a * Power(a, b - 1) * 1LL;
}

int main () {
    int a, b; cin >> a >> b;
    cout << Power(a, b);
}