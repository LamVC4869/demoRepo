#include <iostream>
#include <climits>

using namespace std;

int LinearSeach (int arr[], int n, int x, bool Option);

int main () {
    int n; cin >> n;
    int MaxElement, MinElement;
    MaxElement = INT_MIN;
    MinElement = INT_MAX;
    int arr[n];
    for (int &i : arr) {
        cin >> i;
        MaxElement = max(MaxElement, i);
        MinElement = min(MinElement, i);
    }
    int IndexMin = LinearSeach(arr, n, MinElement, true);
    int IndexMax = LinearSeach(arr, n, MaxElement, false);
    swap(arr[IndexMin], arr[IndexMax]);
    for (int i : arr) cout << i << ' ';
}

int LinearSeach (int arr[], int n, int x, bool Option) {
    int index = 0;
    if (Option) {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == x) {
                index = i;
                break;
            }
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == x) {
                index = i;
            }
        }
    }
    return index;
}