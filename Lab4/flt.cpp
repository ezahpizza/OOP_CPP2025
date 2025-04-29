#include <iostream>

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
            std::cerr << "Error: Division by zero!" << std::endl;
            return FLOAT(0.0f); // Return 0 or could throw an exception
        }
        return FLOAT(value / other.value);
    }

    // Display method
    void display() const {
        std::cout << value;
    }
};

// Overload << operator for easy output
std::ostream& operator<<(std::ostream& os, const FLOAT& f) {
    os << f.getValue();
    return os;
}

int main() {
    // Create FLOAT objects
    FLOAT f1(10.5);
    FLOAT f2(2.5);
    FLOAT result;

    // Display initial values
    std::cout << "f1 = " << f1 << std::endl;
    std::cout << "f2 = " << f2 << std::endl;

    // Addition
    result = f1 + f2;
    std::cout << "f1 + f2 = " << result << std::endl;

    // Subtraction
    result = f1 - f2;
    std::cout << "f1 - f2 = " << result << std::endl;

    // Multiplication
    result = f1 * f2;
    std::cout << "f1 * f2 = " << result << std::endl;

    // Division
    result = f1 / f2;
    std::cout << "f1 / f2 = " << result << std::endl;

    // Test division by zero
    FLOAT f3(0.0);
    std::cout << "\nTesting division by zero:" << std::endl;
    result = f1 / f3;
    std::cout << "f1 / 0 = " << result << std::endl;

    // Chaining operations
    std::cout << "\nChaining operations:" << std::endl;
    result = f1 + f2 * f1 - f2 / f1;
    std::cout << "f1 + f2 * f1 - f2 / f1 = " << result << std::endl;

    return 0;
}