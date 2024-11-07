#include <iostream>

using namespace std;

void BubbleSort (int arr[], int n);

int main () {
    int n; cin >> n;
    int arr[n];
    for (int &i : arr) cin >> i;
    BubbleSort(arr, n);
    for (int i : arr) cout << i << ' ';
}

void BubbleSort (int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}