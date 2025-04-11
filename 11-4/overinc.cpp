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

    Counter& operator++() {
        ++count;
        return *this;
    }

    Counter operator++(int) {
        Counter temp = *this;
        count++;
        return temp;
    }
};

int main() {
    Counter c1(5);

    cout << "Initial value:\n";
    c1.display();

    cout << "\nAfter prefix increment (++c1):\n";
    ++c1;
    c1.display();

    cout << "\nAfter postfix increment (c1++):\n";
    c1++;
    c1.display();

    return 0;
}
