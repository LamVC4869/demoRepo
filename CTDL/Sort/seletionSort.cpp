#include <iostream>

using namespace std;

void seletionSort (int arr[], int n);
void printArray (int arr[], int n);

int main () {
    int n; cin >> n;
    int arr[n];
    for (int &i : arr) cin >> i;
    seletionSort(arr, n);
    printArray(arr, n);
}

void seletionSort (int arr[], int n) {
    int indexMin;
    for (int i = 0; i < n - 1; ++i) {
        indexMin = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[indexMin] > arr[j])
                indexMin = j;
        }
        if (i != indexMin) swap(arr[i], arr[indexMin]);
    }
}

void printArray (int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
}