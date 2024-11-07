#include <iostream>

using namespace std;

int InterpolationSearch (int arr[], int n, int x);

int main () {
    int n, x; cin >> n;
    int arr[n];
    for (int &i : arr) cin >> i;
    cin >> x;
    cout << InterpolationSearch(arr, n, x);
}

int InterpolationSearch (int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left < right && x >= arr[left] && x <= arr[right]) {
        int middle = left + (right - left) * (x - arr[left]) / (arr[right] - arr[left]);
        if (arr[middle] < x) left = middle + 1;
        else if (arr[middle] > x) right = middle - 1;
        else {
            if (middle > 0 && arr[middle - 1] == x) right = middle - 1;
            else return middle;
        }
    }
    return arr[left] == x ? left : -1;
}