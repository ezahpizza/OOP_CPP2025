#include <iostream>
using namespace std;

class BankAccount {
private:
    string depName;
    long accNum;
    string accType;
    int balance;

public:
    void init (string name, long num, string type, int bal) {
        depName = name;
        accNum  = num;
        accType = type;
        balance = bal;
    }

    void deposit (int amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Balance updated." << endl;
        }
        else {
            cout << "Invalid amount." << endl;
        }
    }

    void withdraw (int amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Amount withdrawn.Balance updated." << endl;
        }
        else if (amount < 0) {
            cout << "Invalid amount." << endl;
        }
        else {
            cout << "Insufficient balance." << endl;
        }
    }

    void display () {
        cout << "Name: " << depName << endl;
        cout << "Balance: " << balance << endl;
    }
};

class BankSystem {
private:
    BankAccount accounts[10];
    int count;

public:
    BankSystem() {
        count = 0;
    }

    void addAccount (string name, long num, string type, int bal) {
        if (count < 10) {
            accounts[count].init(name, num, type, bal);
            cout << "Account created with index: " << count << endl;
            count++;
        }
        else {
            cout <<"Cannot add account. Limit reached." << endl;
        }
    }

    void depositAcc (int index, int amount) {
        if (index <= count){
            accounts[index].deposit(amount);
        }
        else {
            cout <<"Invalid index." << endl;
        }
    }

    void withdrawAcc (int index, int amount) {
        if (index <= count){
            accounts[index].withdraw(amount);
        }
        else {
            cout <<"Invalid index." << endl;
        }
    }

    void displayAccount(int index) {
        if (index >= 0 && index < count) {
            accounts[index].display();
        } else {
            cout << "Invalid account index." << endl;
        }
    }

    void displayAllAccounts() {
        for (int i = 0; i < count; i++) {
            cout << "\nAccount Index: " << i << endl;
            accounts[i].display();
            cout << "------------------------" << endl;
        }
    }

};

int main() {
    BankSystem bankSystem;
        
    bankSystem.addAccount("John Doe", 123456789, "Savings", 1000);
    bankSystem.addAccount("Jane Smith", 987654321, "Current", 2000);
    bankSystem.addAccount("Alice Johnson", 456789123, "Savings", 1500);
    
    cout << "\nAll accounts:" << endl;
    bankSystem.displayAllAccounts();
    
    bankSystem.depositAcc(1, 500);
    bankSystem.withdrawAcc(0, 300);
    
    cout << "\nUpdated accounts:" << endl;
    bankSystem.displayAllAccounts();

    return 0;
}