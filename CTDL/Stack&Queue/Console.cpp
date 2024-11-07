#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<bool> used(1000, false);

int main () {
    int n, k;
    cin >> n;
    int arr[n];
    for (int &i : arr) cin >> i;
    cin >> k;
    queue<int> myQueue;
    for (int i = 0; i < n; ++i) {
        if (!used[arr[i]]) {
            if (myQueue.size() < k) {
                myQueue.push(arr[i]);
                used[arr[i]] = true;
            }
            else if (myQueue.size() == k) {
                myQueue.push(arr[i]);
                used[myQueue.front()] = false;
                used[arr[i]] = true;
                myQueue.pop();
            }
        }
    }
    while (!myQueue.empty()) cout << myQueue.front() << ' ', myQueue.pop();
    return (0);
}