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

    void display() {
        cout << "Name: " << name << ", ID: " << id << ", Salary: $" << salary << endl;
    }
};

class TechnicalEmployee : public Employee {
    int dept_no, no_of_projects;
public:
    TechnicalEmployee() : Employee(), dept_no(0), no_of_projects(0) {}
    TechnicalEmployee(string n, int i, double s, int d, int p) 
        : Employee(n, i, s), dept_no(d), no_of_projects(p) {}

    void display() {
        Employee::display();
        cout << "Department No: " << dept_no << ", No of Projects: " << no_of_projects << endl;
    }
};

int main() {
    Employee emp1("Anakin", 101, 75000);
    TechnicalEmployee techEmp1("Kylo", 102, 80000, 5, 3);
    TechnicalEmployee techEmp2("Revan", 102, 80000, 5, 3);

    emp1.display();
    techEmp1.display();
    techEmp2.display();

    return 0;
}