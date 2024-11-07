#include <iostream>
#include <cstring>

using namespace std;

const int LIMIT = 4e6 + 1;
int L, R, resultOfTask(0);
bool isPrime[LIMIT];

void Eratosthenes () {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i < LIMIT; ++i) {
        if (isPrime[i]) {
            for (int j = i*i; j < LIMIT; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int TongCacChuSo (int n) {
    int total = 0;
    while (n) {
        total += n % 10;
        n /= 10;
    }
    return total;
}

int SoluongSoSongNguyenToTrongDoan (int l, int r) {
    int count = 0;
    for (int i = l; i <= r; ++i) {
        if (isPrime[i] && isPrime[TongCacChuSo(i)]) {
            count++;
        }
    }
    return count;
}

int main () {
    Eratosthenes();
    scanf("%d%d", &L, &R);
    int result = SoluongSoSongNguyenToTrongDoan(L, R);
    printf("%d", result);
    return (0);
}