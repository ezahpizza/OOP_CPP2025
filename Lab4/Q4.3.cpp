#include <iostream>

using namespace std;

class FLOAT {
private:
    float value;

public:
    FLOAT() : value(0.0f) {}

    FLOAT(float val) : value(val) {}

    float getValue() const {
        return value;
    }

    void setValue(float val) {
        value = val;
    }

    FLOAT operator+(const FLOAT& other) const {
        return FLOAT(value + other.value);
    }

    FLOAT operator-(const FLOAT& other) const {
        return FLOAT(value - other.value);
    }

    FLOAT operator*(const FLOAT& other) const {
        return FLOAT(value * other.value);
    }

    FLOAT operator/(const FLOAT& other) const {
        if (other.value == 0.0f) {
            cerr << "Error: Division by zero!" << endl;
            return FLOAT(0.0f);
        }
        return FLOAT(value / other.value);
    }

    void display() const {
        cout << value;
    }
};

ostream& operator<<(ostream& os, const FLOAT& f) {
    os << f.getValue();
    return os;
}

int main() {
    FLOAT f1(10.5);
    FLOAT f2(2.5);
    FLOAT result;

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    result = f1 + f2;
    cout << "f1 + f2 = " << result << endl;

    result = f1 - f2;
    cout << "f1 - f2 = " << result << endl;

    result = f1 * f2;
    cout << "f1 * f2 = " << result << endl;

    result = f1 / f2;
    cout << "f1 / f2 = " << result << endl;

    return 0;
}