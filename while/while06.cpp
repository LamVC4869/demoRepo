#include <stdio.h>

long long reverse (long long n) {
    long long answer = 0;
    while (n)
        answer = answer * 10 + n % 10, n /= 10;
    return answer;
}

int main () {
    long long n;
    scanf("%lld", &n);
    long long reverseNum = reverse(n);
    printf("%lld", reverseNum + n);
}