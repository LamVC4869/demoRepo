#include <iostream>

using namespace std;

string Binary;
void backTrack (int n) {
    if (Binary.length() == n) {
        cout << Binary << ' ';
        return;
    }
    Binary.push_back('0');
    backTrack(n);
    Binary.pop_back();

    Binary.push_back('1');
    backTrack(n);
    Binary.pop_back();
}

int main () {
    int n; cin >> n;
    backTrack(n);
}