#include <iostream>

using namespace std;

int BinarySearch (int arr[], int n, int x);

int main () {
    int n, x; cin >> n;
    int arr[n];
    for (int &i : arr) cin >> i;
    cin >> x;
    int index = BinarySearch(arr, n, x);
    cout << index;
}

int BinarySearch (int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left < right) {
        int middle = (left + right)/2;
        if (arr[middle] < x) left = middle + 1;
        else right = middle;
    }
    return arr[left] == x ? left : -1;
}