#include <iostream>
#include <cmath>

using namespace std;

bool used[1000010];
bool isPerfectSquareNumber (int n);
void merge (int arr[], int left, int middle, int right);
void mergeSort(int arr[], int left, int right);
void solve (int arr[], int n);

int main () {
    int n; cin >> n;
    int arr[n];
    for (int &i : arr) cin >> i;
    solve(arr, n);
}

bool isPerfectSquareNumber (int n) {
    return int(sqrt(n)) == sqrt(n);
}

void merge (int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int L[n1], R[n2];
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[middle + i + 1];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = (left + right)/2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}
void solve (int arr[], int n) {
    mergeSort(arr, 0, n - 1);
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (isPerfectSquareNumber(arr[i])) {
            found = true;
            if (!used[arr[i]]) {
                cout << arr[i] << ' ';
                used[arr[i]] = true;
            }
        }
    }
    if (!found) cout << "NULL";
}