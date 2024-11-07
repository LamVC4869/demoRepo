#include <iostream>

using namespace std;

void Recursive (int k, int n, string str) {
    if (str.length() == n) {
        cout << str << '\n';
        return;
    }
    for (int i = 1; i <= k; ++i) {
        str.push_back(i + '0');
        Recursive(k, n, str);
        str.pop_back();
    }
}

int main () {
    int k, n, m;
    cin >> k >> n;
    m = k;
    for (int i = 0; i < n; ++i)
        m *= k;
    cout << m << '\n';
    Recursive(k, n, "");
}