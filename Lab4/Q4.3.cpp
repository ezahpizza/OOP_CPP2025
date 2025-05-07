#include <iostream>

using namespace std;

class FLOAT {
private:
    float value;

public:
    // Default constructor
    FLOAT() : value(0.0f) {}

    // Parameterized constructor
    FLOAT(float val) : value(val) {}

    // Getter method
    float getValue() const {
        return value;
    }

    // Setter method
    void setValue(float val) {
        value = val;
    }

    // Overload + operator
    FLOAT operator+(const FLOAT& other) const {
        return FLOAT(value + other.value);
    }

    // Overload - operator
    FLOAT operator-(const FLOAT& other) const {
        return FLOAT(value - other.value);
    }

    // Overload * operator
    FLOAT operator*(const FLOAT& other) const {
        return FLOAT(value * other.value);
    }

    // Overload / operator
    FLOAT operator/(const FLOAT& other) const {
        // Check for division by zero
        if (other.value == 0.0f) {
            cerr << "Error: Division by zero!" << endl;
            return FLOAT(0.0f); // Return 0 or could throw an exception
        }
        return FLOAT(value / other.value);
    }

    // Display method
    void display() const {
        cout << value;
    }
};

// Overload << operator for easy output
ostream& operator<<(ostream& os, const FLOAT& f) {
    os << f.getValue();
    return os;
}

int main() {
    // Create FLOAT objects
    FLOAT f1(10.5);
    FLOAT f2(2.5);
    FLOAT result;

    // Display initial values
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    // Addition
    result = f1 + f2;
    cout << "f1 + f2 = " << result << endl;

    // Subtraction
    result = f1 - f2;
    cout << "f1 - f2 = " << result << endl;

    // Multiplication
    result = f1 * f2;
    cout << "f1 * f2 = " << result << endl;

    // Division
    result = f1 / f2;
    cout << "f1 / f2 = " << result << endl;

    // Test division by zero
    FLOAT f3(0.0);
    cout << "\nTesting division by zero:" << endl;
    result = f1 / f3;
    cout << "f1 / 0 = " << result << endl;

    // Chaining operations
    cout << "\nChaining operations:" << endl;
    result = f1 + f2 * f1 - f2 / f1;
    cout << "f1 + f2 * f1 - f2 / f1 = " << result << endl;

    return 0;
}