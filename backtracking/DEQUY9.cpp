#include <iostream>

using namespace std;

long long factorial (int n);
long long S (int n);
long long P (int n);

int main () {
    int n;
    cin >> n;
    cout << "S(" << n << ") = " << S(n) << '\n';
    cout << "P(" << n << ") = " << P(n);
}

long long factorial (int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

long long S (int n) {
    if (n == 1) return 1;
    return n*(n + 1)/2 + S(n - 1);
}
long long P (int n) {
    if (n == 1) return 1;
    return factorial(n) + P(n - 1);
}