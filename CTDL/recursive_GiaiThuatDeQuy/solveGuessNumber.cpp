#include <iostream>

using namespace std;

long long GuessNumber (long long n) {
    if (n == 1) return 1;
    return 1 + GuessNumber(n / 2);
}

int main () {
    long long n; cin >> n;
    cout << GuessNumber(n); 
}