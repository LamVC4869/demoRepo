#include <iostream>

using namespace std;

void del (int a[], int& n, int pos) {
    for (int i = pos; i < n - 1; ++i) {
        a[i] = a[i+1];
    }
    n--;
}

void printArr (int a[], int size) {
    for(int i = 0; i < size; ++i) {
        cout << a[i] << ' ';
    }
}

int main () {
    int n, x;
    int a[100];
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << "Array: ";
    printArr(a, n);
    for (int i = 0; i < n; ++i) {
        if (a[i] == x) {
            del(a, n, i);
        }
    }
    cout << "\nNew Array: ";
    printArr(a, n);
    return 0;
}