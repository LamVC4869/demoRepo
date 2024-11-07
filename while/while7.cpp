#include <stdio.h>

int totalOddNumberOfDigit (long long n) {
    int answer = 0;
    while (n) {
        if ((n % 10) & 1)
            answer += n % 10;
        n /= 10;
    }
    return answer;
}

int main () {
    long long n;
    scanf("%lld", &n);
    int result = totalOddNumberOfDigit(n);
    printf("%d", result);
}