#include <stdio.h>

int totalPrimeNumbers (long long n) {
    int answer = 0;
    while (n) {
        int k = n % 10;
        if (k == 2 || k == 3 || k == 5 || k == 7)
            answer += k;
        n /= 10;
    }
    return answer;
}

int main () {
    long long n;
    scanf("%lld", &n);
    printf("%d", totalPrimeNumbers(n));
}