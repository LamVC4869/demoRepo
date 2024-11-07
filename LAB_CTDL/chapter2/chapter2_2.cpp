#include <iostream>
#include <vector>

using namespace std;

int timKiem (int a[], int n, int x) {
    vector<int> list_index;
    for (int i = 0; i < n; ++i) {
        if (a[i] == x) {
            list_index.push_back(i);
        }
    }
    if (!list_index.empty()) {
        cout << "Tat ca vi tri xuat hien: ";
        for (const int& index : list_index) {
            cout << index << ' ';
        }
        return 1;
    }
    return 0;
}

int main () {
    int n, x;
    int a[100];
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (!timKiem(a, n, x)) {
        cout << "Khong tim thay";
    }
    return 0;
}