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

struct Student {
    string name;
    int math, eng;
    Student () {}
    Student (string name, int math, int eng) : name(name), math(math), eng(eng) {}
    friend ostream& operator << (ostream &os, Student s) {
        os << s.name << '-' << s.math << '-' << s.eng;
        return os;
    }
    double avg () {
        int k = this->math + this->eng;
        return 1.0*k/2;
    }
    bool operator > (Student another) {
        return this->avg() > another.avg();
    }
    Student operator = (Student another) {
        this->name = another.name;
        this->math = another.math;
        this->eng = another.eng;
        return *this;
    }
};

vector<Student> List = {{"Tran Mai Ngo", 7, 8}, {"Ly Quoc Tan", 6, 2}, {"Nguyen Minh Phu", 9, 10}, {"Le Nhan To", 6, 5}, {"Ho Duc Trinh", 4, 7}};

void printList () {
    FOR(i, 0, List.size() - 1) {
        cout << i + 1 << ". ";
        cout << List[i];
        if (i < List.size() - 1) cout << '\n';
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    if (n == 1) {
        printList();
    }
    else if (n == 2) {
        Student t = List[0];
        FOR(i, 1, 4) if (List[i] > t) t = List[i];
        cout << t << '-' << fixed << setprecision(1) << t.avg();
    }
    else if (n == 3) {
        List.erase(List.begin() + 2);
        printList();
    }
    else if (n == 4) {
        List[3].math = 5;
        List[3].eng = 3;
        cout << List[3];
    }
    else if (n == 5) {
        Student tmp = {"Doan Anh Tuan", 10, 10};
        List.pb(tmp);
        printList();
    }
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}