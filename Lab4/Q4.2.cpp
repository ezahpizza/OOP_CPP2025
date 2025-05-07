#include <iostream>

class Counter {
private:
    int count;

public:
    Counter(int c = 0) : count(c) {}

    void display() const {
        std::cout << "Count: " << count << std::endl;
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
    std::cout << "Initial value:" << std::endl;
    c1.display();

    std::cout << "\nUsing prefix increment (++c1):" << std::endl;
    ++c1;
    c1.display();

    std::cout << "\nUsing postfix increment (c1++):" << std::endl;
    Counter c2 = c1++;
    std::cout << "c1 after increment: ";
    c1.display();
    std::cout << "c2 after assignment: ";
    c2.display();

    return 0;
}