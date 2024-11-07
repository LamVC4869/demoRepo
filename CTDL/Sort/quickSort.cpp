#include <iostream>

using namespace std;

int LomutoPartition (int arr[], int left, int right);
int HoarePartition (int arr[], int left, int right);
void quickSort1 (int arr[], int left, int right);
void printArray (int arr[], int n);

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    quickSort1(arr, 0, n - 1);
    quickSort2(arr, 0, n - 1);
    printArray(arr, n);
}

int LomutoPartition (int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

int HoarePartition (int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left - 1, j = right + 1;
    while (true) {
        do {--j;} while (arr[j] > pivot);
        do {++i;} while (arr[i] < pivot);
        if (i < j) swap(arr[i], arr[j]);
        else return j;
    }
}

void quickSort1 (int arr[], int left, int right) {
    if (left >= right) return;
    int p = LomutoPartition(arr, left, right);
    quickSort1(arr, left, p - 1);
    quickSort1(arr, p + 1, right);
}

void quickSort2 (int arr[], int left, int right) {
    if (left >= right) return;
    int p = HoarePartition(arr, left, right);
    quickSort2(arr, left, p);
    quickSort2(arr, p + 1, right);
}

void printArray (int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
}