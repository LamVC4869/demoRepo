#include <iostream>
#include <stack>

using namespace std;

void StringCompression (string str) {
    stack<char> myStack;
    string result;
    str.push_back(' ');
    for (char character : str) {
        if (myStack.empty() || myStack.top() == character) myStack.push(character);
        else {
            result.push_back(myStack.top());
            result += to_string(myStack.size());
            while (!myStack.empty()) myStack.pop();
            myStack.push(character);
        }
    }
    cout << result;
}

int main () {
    string str; cin >> str;
    StringCompression(str);
}