#include <iostream>

using namespace std;
int main() {
    int sub1, sub2, sub3;
    float pct;
    char grade;

    cout << "Enter marks for subject 1:" << endl;
    cin >> sub1;
    cout << "Enter marks for subject 2:" << endl;
    cin >> sub2;
    cout << "Enter marks for subject 3:" << endl;
    cin >> sub3;

    pct = (sub1 + sub2 + sub3) / 3.0;

    if(pct >= 90)
        grade = 'O';
    else if(pct > 80 && pct < 90)
        grade = 'A';
    else if(pct > 70 && pct < 80)
        grade = 'B';
    else if(pct > 60 && pct < 70)
        grade = 'C';
    else
        grade = 'F';

    cout << "Percentage : " << pct << endl << "Grade : " << grade << endl;

    return 0;
}
