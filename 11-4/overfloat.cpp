#include <iostream>
using namespace std;

class FLOAT {
private:
    float value;

public:
    FLOAT(float v = 0.0f) : value(v) {}

    FLOAT operator+(const FLOAT& f) const {
        return FLOAT(value + f.value);
    }

    FLOAT operator-(const FLOAT& f) const {
        return FLOAT(value - f.value);
    }

    FLOAT operator*(const FLOAT& f) const {
        return FLOAT(value * f.value);
    }

    FLOAT operator/(const FLOAT& f) const {
        if (f.value != 0.0f) {
            return FLOAT(value / f.value);
        } else {
            cout << "Error: Division by zero!" << endl;
            return FLOAT(); 
        }
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    FLOAT f1(10.5f), f2(2.5f);

    FLOAT sum = f1 + f2;
    FLOAT diff = f1 - f2;
    FLOAT prod = f1 * f2;
    FLOAT quot = f1 / f2;

    cout << "f1 + f2 = "; sum.display();
    cout << "f1 - f2 = "; diff.display();
    cout << "f1 * f2 = "; prod.display();
    cout << "f1 / f2 = "; quot.display();

    return 0;
}