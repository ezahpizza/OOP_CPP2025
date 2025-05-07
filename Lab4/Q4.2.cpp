#include <iostream>

using namespace std;

class Counter {
private:
    int count;

public:
    Counter(int c = 0) : count(c) {}

    void display() const {
        cout << "Count: " << count << endl;
    }

    int getValue() const {
        return count;
    }


    Counter& operator++() {
        ++count;
        return *this;
    }

    Counter operator++(int) {
        Counter temp = *this;
        ++count;
        return temp;
    }
};

int main() {
    Counter c1(5);
    cout << "Initial value:" << endl;
    c1.display();

    cout << "\nUsing prefix increment (++c1):" << endl;
    ++c1;
    c1.display();

    cout << "\nUsing postfix increment (c1++):" << endl;
    Counter c2 = c1++;
    cout << "c1 after increment: ";
    c1.display();
    cout << "c2 after assignment: ";
    c2.display();

    return 0;
}