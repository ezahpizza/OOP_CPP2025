#include <iostream>
using namespace std;

class Demo {
    public:
    Demo() {
        cout <<  "Constructor created";
    }
    ~Demo() {
        cout <<  "\nDestructor created";
    }
};

int main () {
    Demo obj;

    return 0;
}