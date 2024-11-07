#include <iostream>

using namespace std;

int LinearSearch (int arr[], int n, int x);

int main () {
    int n, x; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;
    cout << LinearSearch(arr, n, x);
}

int LinearSearch (int arr[], int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}