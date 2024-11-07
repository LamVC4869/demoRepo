#include <iostream>

using namespace std;

bool SequentialSearch (int arr[], int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == x) {
            return cout << i, true;
        }
    }
    return false;
}

int main () {
    int n, x; cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    if (!SequentialSearch(arr, n, x)) return cout << -1, 0;
}