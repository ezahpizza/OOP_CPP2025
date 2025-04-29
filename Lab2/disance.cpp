#include <iostream>
#include <string>
using namespace std;

class DM;  

class DB {
private:
    int feet;
    int inches;

public:
    void getdata() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
        
        while (inches >= 12) {
            inches -= 12;
            feet++;
        }
    }

    void display() {
        cout << feet << " feet and " << inches << " inches" << endl;
    }

    friend DM addDistance(DM, DB);
    friend DB addDistance(DB, DM);
};

class DM {
private:
    int metres;
    int centimetres;

public:
    void getdata() {
        cout << "Enter metres: ";
        cin >> metres;
        cout << "Enter centimetres: ";
        cin >> centimetres;
        
        // Normalize the values
        while (centimetres >= 100) {
            centimetres -= 100;
            metres++;
        }
    }

    void display() {
        cout << metres << " metres and " << centimetres << " centimetres" << endl;
    }

    friend DM addDistance(DM, DB);
    friend DB addDistance(DB, DM);
};

DM addDistance(DM d1, DB d2) {
    DM result;
    int totalCm = d1.metres * 100 + d1.centimetres + d2.feet * 30.48 + d2.inches * 2.54;
    
    result.metres = totalCm / 100;
    result.centimetres = totalCm % 100;
    
    return result;
}

DB addDistance(DB d1, DM d2) {
    DB result;
    int totalInches = d1.feet * 12 + d1.inches + d2.metres * 39.3701 + d2.centimetres * 0.393701;
    
    result.feet = totalInches / 12;
    result.inches = totalInches % 12;
    
    return result;
}

int main() {

    DM dm;
    DB db;
    int resultType;
    
    cout << "Enter DM object data:" << endl;
    dm.getdata();
    
    cout << "Enter DB object data:" << endl;
    db.getdata();
    
    cout << "\nDM object: ";
    dm.display();
    cout << "DB object: ";
    db.display();
    
    cout << "\nChoose result type (1 for DM, 2 for DB): ";
    cin >> resultType;
    
    if (resultType == 1) {
        DM result = addDistance(dm, db);
        cout << "Result in DM: ";
        result.display();
    } else {
        DB result = addDistance(db, dm);
        cout << "Result in DB: ";
        result.display();
    }

    return 0;
}