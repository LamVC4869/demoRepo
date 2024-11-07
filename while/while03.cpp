#include <stdio.h>

int greatest_odd_divisor (int n) {
    int res = 1;
    for (int i = n; i >= 1; --i) {
        if (!(n % i) && (i & 1)) {
            res = i;
            break;
        }
    }
    return res;
}

int main () {
    int n;
    scanf("%d", &n);
    int result = greatest_odd_divisor(n);
    printf("%d", result);
}