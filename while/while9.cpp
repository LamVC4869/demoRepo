#include <iostream>

int arr[10];

void print () {
    if (arr[2]) 
        std::cout << "2: " << arr[2];
    if (arr[3])
        std::cout << "\n3: " << arr[3];
    if (arr[5])
        std::cout << "\n5: " << arr[5];
    if (arr[7])
        std::cout << "\n7: " << arr[7];
}

void solve (long long n) {
    while (n) {
        arr[n % 10]++;
        n /= 10;
    }
    print();
}

int main () {
    long long n;
    std::cin >> n;
    solve(n);
}