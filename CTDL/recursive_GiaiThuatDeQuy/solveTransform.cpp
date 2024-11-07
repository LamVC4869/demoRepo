#include <iostream>

using namespace std;

int count = 0;

void Recursive (int n, int k) {
    if (k == 0) {
        count++;
        return;
    }
    Recursive(2*n, k - 1);
    if (!((n - 1) % 3) && ((n - 1)/3 & 1)) Recursive((n - 1)/3, k - 1);
}

int main () {
    int n, k; cin >> n >> k;
    Recursive(n, k);
    cout << count;
}