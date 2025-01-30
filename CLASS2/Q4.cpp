#include <iostream>

using namespace std;
int main() {
    char ch;
    int num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Enter an operator:" << endl;
    cin >> ch;

    switch (ch) {
        case '+':
            cout << "The sum of " << num1 << " and " << num2 << " is " << num1 + num2 << endl;
            break;
        case '-':
            cout << "The difference of " << num1 << " and " << num2 << " is " << num1 - num2 << endl;
            break;
        case '*':
            cout << "The product of " << num1 << " and " << num2 << " is " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "The quotient of " << num1 << " and " << num2 << " is " << num1 / num2 << endl;
            else
                cout << "Division by zero." << endl;
            break;
        default:
            cout << "Operator invalid." << endl;
    }

    return 0;
}
