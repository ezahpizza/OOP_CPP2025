#include <iostream>
#include <cmath>

using namespace std;

class Polar {
private:
    double radius;
    double angle; 

public:
    Polar(double r = 0.0, double a = 0.0) : radius(r), angle(a) {}

    double getRadius() const { return radius; }
    double getAngle() const { return angle; }

    double getX() const { return radius * cos(angle); }
    double getY() const { return radius * sin(angle); }

    Polar operator+(const Polar& other) const {
        double x1 = getX();
        double y1 = getY();
        double x2 = other.getX();
        double y2 = other.getY();

        double x_result = x1 + x2;
        double y_result = y1 + y2;

        double r_result = sqrt(x_result * x_result + y_result * y_result);
        double a_result = atan2(y_result, x_result); 

        return Polar(r_result, a_result);
    }

    void display() const {
        cout << "Polar(r=" << radius << ", angle=" << angle << " rad = " 
                  << (angle * 180 / M_PI) << "°)" << endl;
    }
};

int main() {
    Polar p1(5.0, M_PI/4);  
    Polar p2(3.0, M_PI/6);  

    cout << "First point: ";
    p1.display();

    cout << "Second point: ";
    p2.display();

    Polar p3 = p1 + p2;

    cout << "Sum: ";
    p3.display();

    cout << "P1(x,y): (" << p1.getX() << ", " << p1.getY() << ")" << endl;
    cout << "P2(x,y): (" << p2.getX() << ", " << p2.getY() << ")" << endl;
    cout << "P3(x,y): (" << p3.getX() << ", " << p3.getY() << ")" << endl;

    return 0;
}