#include <stdio.h>

int array[100], size(0);

void analysis (int n) {
    while (!(n % 2))
        array[size] = 2, ++size;
    int i(3);
    for (i; i <= n; i += 2) {
        if (!(n % i)) {
            array[size] = i;
            ++size;
            n /= i;
        }
    }
    if (n)
        array[size] = n, ++size;
}

void print () {
    int i(0);
    for (i; i < size; ++i) {
        printf("%d", array[i]);
        if (i < size - 1)
            printf("*");
    }
}

void solve (int n) {
    analysis(n);
    print();
}

int main () {
    int n; 
    scanf("%d", &n);
    solve(n);
    return 0;
}