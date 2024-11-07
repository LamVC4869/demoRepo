#include <iostream>

using namespace std;

void printArray (int arr[], int left, int right);
int BinarySearch (int arr[], int n, int x);
void solveProblem (int a[], int b[], int n, int x);

int main () {
    int n, s; cin >> n;
    int arr[n], newArray[n];
    for (int &i : arr) cin >> i;
    newArray[0] = arr[0];
    for (int i = 1; i < n; ++i) newArray[i] = newArray[i - 1] + arr[i];
    cin >> s;
    solveProblem(arr, newArray, n, s);
}

void printArray (int arr[], int left, int right) {
    for (int i = left; i <= right; ++i) {
        cout << arr[i] << ' ';
    }
}

int BinarySearch (int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left < right) {
        int middle = (left + right)/2;
        if (arr[middle] < x) left = middle + 1;
        else right = middle;
    }
    return arr[left] == x ? left : -1;
}

void solveProblem (int a[], int b[], int n, int x) {
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (b[i] == x) {
            printArray(a, 0, i);
            return;
        }
        else if (b[i] > x) {
            int index = BinarySearch(b, n, b[i] - x);
            if (index != -1) {
                found = true;
                printArray(a, index + 1, i);
                return;
            }
        }
    }
    if (!found) cout << -1;
}