#include <iostream>
#include <cmath>

class Polar {
private:
    double radius;
    double angle; // in radians

public:
    // Constructor
    Polar(double r = 0.0, double a = 0.0) : radius(r), angle(a) {}

    // Getters
    double getRadius() const { return radius; }
    double getAngle() const { return angle; }

    // Conversion to rectangular coordinates
    double getX() const { return radius * cos(angle); }
    double getY() const { return radius * sin(angle); }

    // Overloading + operator
    Polar operator+(const Polar& other) const {
        // Convert both points to rectangular coordinates
        double x1 = getX();
        double y1 = getY();
        double x2 = other.getX();
        double y2 = other.getY();

        // Add rectangular coordinates
        double x_result = x1 + x2;
        double y_result = y1 + y2;

        // Convert back to polar coordinates
        double r_result = sqrt(x_result * x_result + y_result * y_result);
        double a_result = atan2(y_result, x_result); // Using atan2 to handle all quadrants

        // Return the result as a new Polar object
        return Polar(r_result, a_result);
    }

    // Display method
    void display() const {
        std::cout << "Polar(r=" << radius << ", angle=" << angle << " rad = " 
                  << (angle * 180 / M_PI) << "°)" << std::endl;
    }
};

int main() {
    // Create two Polar objects
    Polar p1(5.0, M_PI/4);  // 45 degrees
    Polar p2(3.0, M_PI/6);  // 30 degrees

    std::cout << "First point: ";
    p1.display();

    std::cout << "Second point: ";
    p2.display();

    // Add the two points
    Polar p3 = p1 + p2;

    std::cout << "Sum: ";
    p3.display();

    // Verify the result by comparing with rectangular coordinates
    std::cout << "\nVerification:" << std::endl;
    std::cout << "P1(x,y): (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
    std::cout << "P2(x,y): (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;
    std::cout << "P3(x,y): (" << p3.getX() << ", " << p3.getY() << ")" << std::endl;
    std::cout << "P1(x,y) + P2(x,y): (" << p1.getX() + p2.getX() << ", " 
              << p1.getY() + p2.getY() << ")" << std::endl;

    return 0;
}