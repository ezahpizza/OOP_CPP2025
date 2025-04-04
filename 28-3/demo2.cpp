#include <iostream>
using namespace std;

int count = 0;

class Demo {
    public:
    Demo() {
        count++;
        cout << endl <<"object created" << count;
    }
    ~Demo() {
        count--;
        cout << endl << "object destroyed" << count;
    }
};

int main () {
    Demo obj1, obj2, obj3;

    return 0;
}