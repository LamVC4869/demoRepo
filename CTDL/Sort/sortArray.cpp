#include <iostream>

using namespace std;

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
    if (right <= left) return;
    int p = LomutoPartition(arr, left, right);
    quickSort(arr, left, p - 1);
    quickSort(arr, p + 1, right);
}

void solve (int arr[], int b[], int n, int index) {
    quickSort(b, 0, index - 1);
    int j = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] < 0) {
            arr[i] = b[j++];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            arr[i] = b[j++];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
}

int main () {
    int n, index = 0;
    int arr[1001], b[1001];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] != 0) b[index++] = arr[i];
    }
    solve(arr, b, n, index);
    return 0;
}