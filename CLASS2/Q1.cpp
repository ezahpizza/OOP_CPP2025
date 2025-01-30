#include <iostream>

using namespace std;
int main() {
    int num1, num2, max;

    cout << "Enter a number:" << endl;
    cin >> num1;
    cout << "Enter another number:" << endl;
    cin >> num2;

    if (num1 > num2) 
        max = num1;
    else
        max = num2;

    cout << "The maximum number is: " << max << endl;

    return 0;
}
