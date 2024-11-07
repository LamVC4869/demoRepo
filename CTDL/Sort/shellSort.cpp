#include <iostream>

using namespace std;

int k = 0;

void shellSort (int arr[], int n);
void printArray (int arr[], int n);

int main () {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    shellSort(arr, n);
    printArray(arr, n);
    return 0;
}

void shellSort (int arr[], int n) {
    for (int interval = n/2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; ++i) {
            int temp = arr[i];
            int j = i;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                arr[j] = arr[j - interval];
            }
            cout << "j = " << j << '\n';
            arr[j] = temp;
        }
    }
}
void printArray (int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << *(arr + i) << ' ';
    }
}