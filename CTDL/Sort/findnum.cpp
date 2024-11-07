#include <iostream>

using namespace std;

int n, arr[1001];

int LomutoPartition (int arr[], int left, int right);
int HoarePartition (int arr[], int left, int right);
void LomutoQuickSort (int arr[], int left, int right);
void HoareQuickSort (int arr[], int left, int right);
void solve (int arr[], int n);

int main () {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    solve(arr, n);
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
        do { --j; } while (arr[j] > pivot);
        do { ++i; } while (arr[i] < pivot);
        if (i < j) swap(arr[i], arr[j]);
        else return j;
    }
}

void LomutoQuickSort (int arr[], int left, int right) {
    if (left < right) {
        int p = LomutoPartition(arr, left, right);
        LomutoQuickSort(arr, left, p - 1);
        LomutoQuickSort(arr, p + 1, right);
    }
}
void HoareQuickSort (int arr[], int left, int right) {
    if (left < right) {
        int p = HoarePartition(arr, left, right);
        HoareQuickSort(arr, left, p);
        HoareQuickSort(arr, p + 1, right);
    }
}
void solve (int arr[], int n) {
    HoareQuickSort(arr, 0, n - 1);
    if (arr[0] > 0) {
        cout << 0;
        return;
    }
    bool found = false;
    for (int i = 1; i < n; ++i) {
        if (arr[i] - arr[i - 1] > 1) {
            found = true;
            cout << arr[i - 1] + 1;
            return;
        }
    }
    if (!found) cout << arr[n - 1] + 1;
}