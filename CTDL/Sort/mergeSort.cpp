#include <iostream>

using namespace std;

void merge (int arr[], int left, int middle, int right);
void mergeSort (int arr[], int left, int right);
void printArray (int arr[], int n);

int main () {
    int n; cin >> n;
    int arr[n];
    for (int &i : arr) cin >> i;
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
}

void merge (int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int L[n1], R[n2];
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[i + middle + 1];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (i < n2) arr[k++] = R[j++];
}

void mergeSort (int arr[], int left, int right) {
    if (right <= left) return;
    int middle = (left + right)/2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

void printArray (int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
}