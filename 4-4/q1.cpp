#include <iostream>

using namespace std;

class demo {
    int x;
    int y;

public:
    void getData() {
        cout << "Enter the value of x adn y. "; cin >> x >> y;
    }

    void display() {
        cout << "Value of x = " << x << endl;
        cout << "Value of y = " << y << endl;
    }

    void operator ++();
    void operator --();
};

void demo::operator ++() {
    x++; y++;
}
void demo::operator --() {
    x--; y--;
}

int main() {
    demo a;
    a.getData();
    a.display();
    ++a;
    a.display();
    --a;
    a.display();

    return 0;
}
