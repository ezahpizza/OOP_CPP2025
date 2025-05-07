#include <iostream>
#include <cstring>
using namespace std;

class String {
    char *str;
    int length;

public:
    String() {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }

    String(const char *s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    String(const String &s) {
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }

    ~String() {
        delete[] str;
    }

    String& operator=(const String &s) {
        if (this != &s) {
            delete[] str;
            length = s.length;
            str = new char[length + 1];
            strcpy(str, s.str);
        }
        return *this;
    }

    String operator+(const String &s) {
        String temp;
        temp.length = length + s.length;
        delete[] temp.str;
        temp.str = new char[temp.length + 1];
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }

    void display() const {
        cout << str << endl;
    }
};

int main () {

    String s1; 
    String s2("Well done!"); 
    String s3;

    cout << "s1: ";
    s1.display();

    cout << "s2: ";
    s2.display();

    s3 = s1 + s2; 
    cout << "s3 (s1 + s2): ";
    s3.display();

    s1 = s2; 
    cout << "s1 after assignment from s2: ";
    s1.display();
    
    return 0;
}