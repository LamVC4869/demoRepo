#include <iostream>

using namespace std;

void Recursive (int k, int n, string str) {
    if (str.length() == k) {
        cout << str << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        char chr = i + '0';
        if (str.find(chr) == -1) {
            str.push_back(chr);
            Recursive(k, n, str);
            str.pop_back();
        }
    }
}

int main () {
    int k, n;
    cin >> k >> n;
    Recursive(k, n, "");
}