#include <bits/stdc++.h>
#define ll long long

using namespace std;

string add (string a, string b) {
    string ans = "";
    ll n = max(a.length(), b.length()), reminder = 0;
    while (a.length() < n) a = "0" + a;
    while (b.length() < n) b = "0" + b;
    for (int i = n - 1; i >= 0; --i) {
        int num = int(a[i] - '0') + int(b[i] - '0') + reminder;
        ans = char(num % 10 + '0') + ans;
        reminder = num / 10;
    }
    if (reminder) ans = char(reminder + '0') + ans;
    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, temp, ans = "0"; cin >> s;
    for (char& c : s) {
        if (!isdigit(c)) c = ' ';
    }
    stringstream ss(s);
    while (ss >> temp) {
        ans = add(ans, temp);
    }
    cout << ans;
}