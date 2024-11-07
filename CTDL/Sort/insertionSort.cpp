#include <iostream>

using namespace std;

void InsertionSort (int arr[], int n);
void printArray (int arr[], int n);

int main () {
    int n; cin >> n;
    int arr[n];
    for (int &i : arr) cin >> i;
    InsertionSort(arr, n);
    printArray(arr, n);
}

void printArray (int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
}

void InsertionSort (int arr[], int n) {
    int index, value;
    for (int i = 1; i < n; ++i) {
        index = i;
        value = arr[i];
        while (index > 0 && arr[index - 1] > value) {
            arr[index] = arr[index - 1];
            index--;
        }
        arr[index] = value;
    }
}