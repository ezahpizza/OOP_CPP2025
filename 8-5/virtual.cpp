#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int rollno; char name[20];

public:
    void accept() {
        cout << "enter the roll number of the student: " << endl;
        cin >> rollno;

        cout << "enter the name of the student: " << endl;
        cin >> name;
    }

    void display() {
        cout << endl << "Roll no: " << "\t Name: " << name << endl;
    }

    void modify (int r, char* s) {
        rollno = r;
        strcpy(name, s);
    }
};

class exam: public Student {
private:
    int m1; int m2; int tm;

public:
    void accept() {
        Student:: accept();
        cout << "enter the marks in 2 subjects" << endl;
        cin >> m1 >> m2;
    }

    void display() {
        Student::display;
        cout << endl << "subject 1 marks: " << m1 << "\t subject 2 marks: "<< endl;
        cout << endl << "total marks" <<tm;
    }

    void cal() {
        tm = m1 + m2;
    }
};

