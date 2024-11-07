#include <iostream>

using namespace std;

void LinearSearch (int arr[], int n) {
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (!(i & 1) && (arr[i] & 1)) {
            cout << arr[i] << ' ';
            found = true;
        }
    }
    if (!found) cout << "NULL";
}

int main () {
    int n; cin >> n;
    int arr[n];
    for (int &i : arr) cin >> i;
    LinearSearch(arr, n);
}