#include <iostream>

using namespace std;

int n, arr[1001];
int HoarePartition (int arr[], int left, int right);
void quickSort (int arr[], int left, int right);
void solve (int arr[], int n);

int main () {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    solve(arr, n);
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
void quickSort (int arr[], int left, int right) {
    if (left < right) {
        int p = HoarePartition(arr, left, right);
        quickSort(arr, left, p);
        quickSort(arr, p + 1, right);
    }
}

void solve (int arr[], int n) {
    quickSort(arr, 0, n - 1);
    int count = 1;
    for (int i = 1; i < n + 1; ++i) {
        if (arr[i] == arr[i - 1]) count++;
        else {
            cout << arr[i - 1] << ' ' << count << "; ";
            count = 1;
        }
    }

}