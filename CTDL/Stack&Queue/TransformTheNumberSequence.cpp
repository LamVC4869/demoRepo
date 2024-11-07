#include <iostream>
#include <queue>

using namespace std;

int main () {
    int n, element, k; cin >> n;
    queue<int> myQueue;
    while (n--) cin >> element, myQueue.push(element);
    cin >> k;
    while (k--) myQueue.push(myQueue.front()), myQueue.pop();
    while (!myQueue.empty()) cout << myQueue.front() << ' ', myQueue.pop();
}