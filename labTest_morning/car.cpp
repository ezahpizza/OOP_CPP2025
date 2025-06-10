#include <iostream>
#include <string>

using namespace std;

class Car {
    string make;
    string model;   
    double price;
public: 
    Car () : make("Unknown"), model("Unknown"), price(0.0) {}
    Car(string m, string mod, double p) : make(m), model(mod), price(p) {}

    void display() {
        cout << "Make: " << make << ", Model: " << model << ", Price: $" << price << endl;
    }

    void costly_car(Car a, Car b) {
        if (a.price > b.price) {
            cout << "Costly Car: ";
            a.display();
        } else if (b.price > a.price) {
            cout << "Costly Car: ";
            b.display();
        } else {
            cout << "Both cars have the same price." << endl;
        }
    }
};

int main() {
    Car car1("Toyota", "Camry", 24000);
    Car car2("Honda", "Accord", 26000);

    car1.display();
    car2.display();

    car1.costly_car(car1, car2);

    return 0;
}