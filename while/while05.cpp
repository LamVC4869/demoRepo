#include <stdio.h>

long long totalNumberOfDigit (long long n) {
    long long answer = 0;
    while (n) {
        answer += n % 10;
        n /= 10;
    }
    return answer;
}

int main () {
    long long n; scanf("%lld", &n);
    long long result = totalNumberOfDigit(n);
    printf("%lld", result);
}