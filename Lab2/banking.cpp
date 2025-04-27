#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string depositorName;
    long accountNumber;
    string accountType;
    double balance;

public:
    void initialize(string name, long accNum, string type, double initialBalance) {
        depositorName = name;
        accountNumber = accNum;
        accountType = type;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount " << amount << " deposited successfully." << endl;
        } else {
            cout << "Invalid amount for deposit." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount " << amount << " withdrawn successfully." << endl;
        } else if (amount <= 0) {
            cout << "Invalid amount for withdrawal." << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    void display() {
        cout << "Name: " << depositorName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
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

    void addAccount(string name, long accNum, string type, double initialBalance) {
        if (count < 10) {
            accounts[count].initialize(name, accNum, type, initialBalance);
            cout << "Account created successfully with index: " << count << endl;
            count++;
        } else {
            cout << "Cannot create more accounts. Limit reached." << endl;
        }
    }

    void depositToAccount(int index, double amount) {
        if (index >= 0 && index < count) {
            accounts[index].deposit(amount);
        } else {
            cout << "Invalid account index." << endl;
        }
    }

    void withdrawFromAccount(int index, double amount) {
        if (index >= 0 && index < count) {
            accounts[index].withdraw(amount);
        } else {
            cout << "Invalid account index." << endl;
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
    int choice;
    cout << "Choose problem to test:" << endl;
    cout << "1. Bank Account" << endl;
    cout << "2. Bank System for 10 customers" << endl;
    cout << "Enter choice (1-2): ";
    cin >> choice;

    if (choice == 1) {
        BankAccount account;
        account.initialize("John Doe", 123456789, "Savings", 1000);
        
        cout << "\nInitial details:" << endl;
        account.display();
        
        account.deposit(500);
        cout << "\nAfter deposit:" << endl;
        account.display();
        
        account.withdraw(200);
        cout << "\nAfter withdrawal:" << endl;
        account.display();
        
        account.withdraw(2000);  
    } 
    else if (choice == 2) {
        BankSystem bankSystem;
        
        bankSystem.addAccount("John Doe", 123456789, "Savings", 1000);
        bankSystem.addAccount("Jane Smith", 987654321, "Current", 2000);
        bankSystem.addAccount("Alice Johnson", 456789123, "Savings", 1500);
        
        cout << "\nAll accounts:" << endl;
        bankSystem.displayAllAccounts();
        
        bankSystem.depositToAccount(1, 500);
        bankSystem.withdrawFromAccount(0, 300);
        
        cout << "\nUpdated accounts:" << endl;
        bankSystem.displayAllAccounts();
    } 
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}