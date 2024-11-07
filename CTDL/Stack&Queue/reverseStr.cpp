#include <iostream>
#include <stack>

using namespace std;

string reverseString (const string &str) {
    string result;
    stack<char> myStack;
    for (char character : str) myStack.push(character);
    while (!myStack.empty()) {
        result.push_back(myStack.top());
        myStack.pop();
    }
    return result;
}

int main () {
    string str;
    getline(cin, str);
    str = reverseString(str);
    cout << str;
}