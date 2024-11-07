#include <iostream>

using namespace std;

string Permutation;
void backTrack (int n) {
    if (Permutation.length() == n) {
        cout << Permutation << ' ';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (Permutation.find(i + '0') == -1) {
            Permutation.push_back(i + '0');
            backTrack(n);
            Permutation.pop_back();
        }
    }
}

int main () {
    int n; cin >> n;
    backTrack(n);
}