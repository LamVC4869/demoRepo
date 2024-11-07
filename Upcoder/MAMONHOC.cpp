#include <bits/stdc++.h>
#define ifile freopen(".inp", "r", stdin)
#define ofile freopen(".out", "w", stdout)
#define setup(a, c) memset(a, c, sizeof(a))
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FOD(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define rz resize
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string vietTatTatCa (const string& str) {
    string temp = str;
    string result;
    stringstream ss(temp);
    while (ss >> temp) {
        result.pb(toupper(temp[0]));
    }
    return result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    cin.ignore();
    vector<string> listStr(n);
    for (string& str : listStr) {
        getline(cin, str);
    }
    unordered_set<string> mySet;
    for (const string& str : listStr) {
        string idSubject = vietTatTatCa(str);
        if (mySet.find(idSubject) == mySet.end()) {
            mySet.insert(idSubject);
            cout << idSubject << '\n';
        }
        else {
            string temp, k, text = idSubject;
            stack<string> myStack;
            stringstream ss(str);
            while (getline(ss, temp, ' ')) myStack.push(temp);
            while (true) {
                if (mySet.find(text + k) == mySet.end()) {
                    cout << text + k << '\n';
                    break;
                }
                k.pb(text.back());
                text.pob();
                k.pb(myStack.top().back());
                myStack.pop();
                if (mySet.find(text + k) == mySet.end()) {
                    idSubject = text + k;
                    text = text + k;
                    mySet.insert(text);
                    cout << text << '\n';
                    break;
                }
                else {
                    text.pob();
                    string tmp;
                    tmp.pb(toupper(myStack.top()[0]));
                    tmp.pb(myStack.top().back());
                    k = tmp + k;
                }
            }
        }
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}