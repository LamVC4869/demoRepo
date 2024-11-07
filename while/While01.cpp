#include <stdio.h>

using namespace std;

int countNumbers (long long n) {
    int count = 0;
    while (n) {
        count++;
        n /= 10;
    }
    return count;
}

int main () {
    long long n;
    scanf("%lld", &n);
    printf("%d", countNumbers(n));
    return 0;
}