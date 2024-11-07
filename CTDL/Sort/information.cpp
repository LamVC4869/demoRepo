#include <iostream>

using namespace std;

int n, k, arr[1001];
int LomutoPartition (int arr[], int left, int right);
void quickSort (int arr[], int left, int right);
void solve (int arr[], int n, int k);

int main () {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> k;
    solve(arr, n, k);
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
void quickSort (int arr[], int left, int right) {
    if (left < right) {
        int p = LomutoPartition(arr, left, right);
        quickSort(arr, left, p - 1);
        quickSort(arr, p + 1, right);
    }
}
void solve (int arr[], int n, int k) {
    quickSort(arr, 0, n - 1);
    int count = 0;
    for (int i = 1; i < n; ++i) {
        count += (arr[i] - arr[i - 1] > k);
    }
    cout << count + 1;
}