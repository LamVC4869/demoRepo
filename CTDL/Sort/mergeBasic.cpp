//Nhập 2 số n và m, nhập vào 2 mảng đã được sắp xếp sau đó trộn chúng lại thành 1 dãy không giảm và in ra màn hình
#include <iostream>
#include <vector>

using namespace std;

vector<int> merge (int a[], int b[], int n, int m);
void printArray (const vector<int>& myArray);

int main () {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    vector<int> myArray = merge(a, b, n, m);
    printArray(myArray);
}

vector<int> merge (int a[], int b[], int n, int m) {
    vector<int> myVector;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            myVector.push_back(a[i++]);
        }
        else myVector.push_back(b[j++]);
    }
    while (i < n) myVector.push_back(a[i++]);
    while (j < m) myVector.push_back(b[j++]);
    return myVector;
}

void printArray (const vector<int>& myArray) {
    for (const int& i : myArray) cout << i << ' ';
}