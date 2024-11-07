#include <iostream>

using namespace std;

int SoLuongSinhVien, SoLuongBaiThi;

class Student {
    private:
        string id;
        int n;
        double *scores;
    public:
        Student (string id = "", int n = 0, double *scores = new double [15]) : id(id), n(n), scores(scores) {}
        Student (const Student& another) {
            this->id = another.id;
            this->n = another.n;
            this->scores = another.scores;
        }
        int getUnit () {
            return n;
        }
        double getAvgScore () {
            double sum = 0;
            for (int i = 0; i < this->n; ++i) sum += this->scores[i];
            return sum * 1.0 / SoLuongBaiThi;
        }
        friend istream& operator >> (istream &is, Student &student) {
            is >> student.id;
            double scoreOfTest;
            while (is >> scoreOfTest) {
                if (scoreOfTest == -1) return is;
                student.scores[student.n++] = scoreOfTest;
            }
            return is;
        }
        friend ostream& operator << (ostream &os, Student student) {
            os << student.id << '-' << student.getUnit() << '-' << student.getAvgScore();
            return os << '\n';
        }
};

int main () {
    cin >> SoLuongSinhVien >> SoLuongBaiThi;
    Student *students = new Student [SoLuongSinhVien];
    for (int i = 0; i < SoLuongSinhVien; ++i) cin >> students[i];
    for (int i = 0; i < SoLuongSinhVien; ++i) cout << students[i];
    delete []students;
    return 0;
}