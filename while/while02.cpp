#include <iostream>

long long reverseNumber (long long n) {
    long long res = 0;
    while (n) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int main () {
    long long n;
    scanf("%lld", &n);
    long long result = reverseNumber(n);
    printf("%lld", result);
    return 0;
}