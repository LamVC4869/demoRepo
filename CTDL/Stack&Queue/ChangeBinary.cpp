#include <iostream>
#include <stack>

using namespace std;

void convertToBinary (int n) {
    stack<int> myStack;
    while (n) {
        myStack.push(n % 2);
        n >>= 1;
    }
    while (!myStack.empty()) {
        cout << myStack.top();
        myStack.pop();
    }
}

int main () {
    int n; cin >> n;
    convertToBinary(n);
}