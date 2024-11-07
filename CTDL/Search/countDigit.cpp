#include <iostream>

using namespace std;

int countDigit (int arr[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; ++i) 
        count += arr[i] == x;
    return count;
}

int main () {
    int n, x; cin >> n;
    int arr[n];
    for (int &i : arr) cin >> i;
    cin >> x;
    int count = countDigit(arr, n, x);
    cout << count;
}