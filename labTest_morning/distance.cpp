#include <iostream>

using namespace std;

class Distance {
    int feet, inches;
public:
    Distance(int f = 0, int i = 0) : feet(f), inches(i) {}

    void display() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }

    Distance operator+(const Distance& d) const {
        int totalFeet = feet + d.feet;
        int totalInches = inches + d.inches;

        totalFeet += totalInches / 12;
        totalInches %= 12;
        
        return Distance(totalFeet, totalInches);
    }
};

int main() {
    Distance d1(5, 9);
    Distance d2(3, 4);

    cout << "Distance 1: ";
    d1.display();
    
    cout << "Distance 2: ";
    d2.display();

    Distance d3 = d1 + d2;
    
    cout << "Sum of distances: ";
    d3.display();

    return 0;
}