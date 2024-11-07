#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 1;
int T, N;
long long factorial[MAXN];

void sievePrevious () {
    factorial[0] = factorial[1] = 1;
    for (int i = 2; i < MAXN; ++i) factorial[i] = ((i % MOD) * (factorial[i - 1] % MOD)) % MOD;
}

int main () {
    sievePrevious();
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        printf("%lld\n", factorial[N]);
    }
    return (0);
}