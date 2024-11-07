#include <iostream>

using namespace std;

string Combination;
void backTrack (int k, int n) {
    if (Combination.length() == n) {
        cout << Combination << ' ';
        return;
    }
    for (int i = 1; i <= k; ++i) {
        if (Combination.empty() || i > Combination.back() - '0') {
            Combination.push_back(i + '0');
            backTrack(k, n);
            Combination.pop_back();
        }
    }
}

int main () {
    int k, n; cin >> k >> n;
    backTrack(k, n);
}