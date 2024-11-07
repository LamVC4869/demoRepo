#include <iostream>

using namespace std;

void Recursive (int n, string str) {
    if (str.length() == n) {
        cout << str << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        char chr = i + '0';
        if (!str.find(chr)) {
            str.push_back(chr);
            Recursive(n, str);
            str.pop_back();
        }
    }
}

int main () {
    int n, m = 1; 
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        m *= i;
    }
    cout << m << '\n';
    Recursive(n, "");
}