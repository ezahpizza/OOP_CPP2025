#include <iostream>
using namespace std;

class Complex {
    private:
        float real;
        float img;

    public:
        Complex() : real(0), img(0) {}
        Complex(float real, float img) : real(real), img(img){}

        static Complex addComplex (const Complex& obj1, const Complex& obj2) {
            Complex temp;
            temp.real = obj1.real + obj2.real;
            temp.img = obj1.img + obj2.img;
            return temp;
    }

    void display() {
        if (img < 0)
            cout << "Output Complex number: " << real << img << "i";
        else
            cout << "Output Complex number: " << real << "+" << img << "i";
    }
};

int main() {
    Complex c1(1.0f, 2.0f);
    Complex c2(1.0f, 3.0f);

    Complex result = Complex::addComplex(c1, c2);
    result.display();

    return 0;
}




