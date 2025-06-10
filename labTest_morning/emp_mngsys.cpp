#include <iostream>
#include <string>

using namespace std;

class Employee {

protected:
    string name;
    int id;
    double salary;

public:
    Employee() : name("Unknown"), id(0), salary(0.0) {}
    Employee(string n, int i, double s) : name(n), id(i), salary(s) {}
    ~Employee() {}	
    virtual void display() = 0; 
};

class Manager : public Employee {
    string department;    
public:
    Manager() : Employee(), department("Unknown") {}
    Manager(string n, int i, double s, string d) 
        : Employee(n, i, s), department(d) {}

    void display() override {
        cout << "Name: " << name << ", ID: " << id << ", Salary: $" << salary 
             << ", Department: " << department << endl;
    }
};

int main() {
    Employee* emp1 = new Manager("Anakin", 101, 75000, "IT");
    Employee* emp2 = new Manager("Padme", 102, 80000, "HR");

    emp1->display();
    emp2->display();

    return 0;
}