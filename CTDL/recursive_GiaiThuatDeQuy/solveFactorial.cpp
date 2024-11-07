#include <iostream>
#define ll long long

using namespace std;

ll factorial (int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main () {
    int n; cin >> n;
    cout << factorial(n);
}