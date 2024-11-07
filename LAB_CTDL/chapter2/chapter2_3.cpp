#include <iostream>

using namespace std;

int tkNhiPhan (int a[], int n, int x, int &i) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + r >> 1;
        if (a[m] == x) {
            return m;
        }
        else if (a[m] > x) {
            i++;
            r = m - 1;
        }
        else {
            i++;
            l = m + 1;
        }
    }
    return -1;
}

int main () {
    int n, x, count = 0;
    int a[100];
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (tkNhiPhan(a, n, x, count) == -1) {
        cout << "Khong tim thay";
    }
    else {
        cout << "So lan chia doi cua mang: " << count << '\n';
        int l = 0, r = n - 1, j = 1;
        while (l <= r) {
            int m = l + r >> 1;
            if (a[m] == x) break;
            else {
                cout << "Lan " << j++ << ": x = " << x << " nam trong doan [";
                if (a[m] > x) {
                    cout << l << ".." << m - 1;
                    r = m - 1;
                }
                else {
                    cout << m + 1 << ".." << r;
                    l = m + 1;
                }
                    cout << "]" << " // mid = " << m << '\n';
            }
        }
    }
    return 0;
}