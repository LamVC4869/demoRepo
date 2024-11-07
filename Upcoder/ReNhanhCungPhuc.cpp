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

const int MAXN = 11;
vector<float> scores(MAXN);
string physical_education;
float Math, Literature, English;

float avg (const vector<float>& scores) {
    float sum = 0;
    for (const float& i : scores) {
        sum += i;
    }
    return 1.0*sum/MAXN;
}

int numberOfSubjectNotPassed (const vector<float>& scores) {
    int count = 0;
    for (const float& score : scores) {
        count += score < 5.0;
    }
    return count;
}

string title (const vector<float>& scores, const string& physical_education) {
    if (physical_education[0] == 'K') return "Yeu.";
    string result = "Yeu.";
    bool good = true, Kha = true, trungBinh = true;
    for (const float& i : scores) {
        if (i < 6.5) 
            good = false;
        if (i < 5) 
            Kha = false;
        if (i < 3.5)
            trungBinh = false;
    }
    if ((Math >= 8 || Literature >= 8 || English >= 8) && avg(scores) >= 8 && good)
        result = "Gioi.";
    else if ((Math >= 6.5 || Literature >= 6.5 || English >= 6.5) && avg(scores) >= 6.5 && Kha)
        result = "Kha.";
    else if ((Math >= 5 || Literature >= 5 || English >= 5) && avg(scores) >= 5 && trungBinh)
        result = "Trung binh."; 
    return result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    FOR(i, 0, MAXN - 1) {
        cin >> scores[i];
    }
    Math = scores[0];
    Literature = scores[3];
    English = scores[4];
    cin >> physical_education;
    cout << "- Phúc bi khong che " << numberOfSubjectNotPassed(scores) << " mon.\n";
    cout << "- Diem trung binh 12 mon hien tai cua Phúc: " << fixed << setprecision(2) << avg(scores) << '\n';
    string t = title(scores, physical_education);
    cout << "- Phúc hien tai dang xep loai: " << t << '\n';
    if (t == "Gioi")
        cout << "- Làm tốt lắm Phúc.";
    else 
        cout << "- Không sao đâu, cố lên nhé Phúc, đừng bỏ cuộc.";
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}