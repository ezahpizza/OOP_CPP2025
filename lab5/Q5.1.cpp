#include <iostream>
#include <cstring>

using namespace std;

class Staff {
    public:
        int code;
        char name[100];
        
        void set_info (char *n, int c) {
            strcpy(name, n);
            code = c;
        }
};

class Teacher : public Staff {
    protected:
        char sub[100], publication[100];
    
    public:
        void set_details (char *s, char *p) {
            strcpy(sub, s);
            strcpy(publication, p);
        }

        void show() {
            cout << "Name: " << name << endl;
            cout << "Code: " << code << endl;
            cout << "Subject: " << sub << endl;
            cout << "Publication: " << publication << endl;
        }
};

class Officer : public Staff {
    protected:
        char grade[100];
    
    public:
        void set_details (char *g) {
            strcpy(grade, g);
        }

        void show() {
            cout << "Name: " << name << endl;
            cout << "Code: " << code << endl;
            cout << "Grade: " << grade << endl;
        }
};

class Typist : public Staff {
    protected:
        float speed;
    
    public:
        void set_speed (float s) {
            speed = s;
        }
};

class Regular : public Typist {
    protected:
        float wage;
    
    public:
        void set_wage(float w) {
            wage = w;
        }

        void show() {
            cout << "Name: " << name << endl;
            cout << "Code: " << code << endl;
            cout << "Speed: " << speed << endl;
            cout << "Wage: " << wage << endl;
        }
};

class Casual : public Typist {
    protected:
        float wage;
    
    public:
        void set_wage(float w) {
            wage = w;
        }

        void show() {
            cout << "Name: " << name << endl;
            cout << "Code: " << code << endl;
            cout << "Speed: " << speed << endl;
            cout << "Wage: " << wage << endl;
        }
};

int main() {
    Teacher t;
    t.set_info ("CPP", 420);
    t.set_details ("Prog CPP", "T. Hill");

    Officer o;
    o.set_info ("Samael", 666);
    o.set_details ("Grand Duke");

    Regular rt;
    rt.set_info ("Baal", 777);
    rt.set_speed (66.6);
    rt.set_wage (666);

    Casual ct;
    ct.set_info ("Beelzebul", 888);
    ct.set_speed (333);
    ct.set_wage (111);

    cout << "About the teacher: " << endl;
    t.show();

    cout << "About the Officer: " << endl;
    o.show();

    cout << "About the Regular typist: " << endl;
    rt.show();

    cout << "About the Casual typist: " << endl;
    ct.show();

    return 0;
}


// Output:

// About the teacher: 
// Name: CPP
// Code: 420
// Subject: Prog CPP
// Publication: T. Hill
// About the Officer: 
// Name: Samael
// Code: 666
// Grade: Grand Duke
// About the Regular typist: 
// Name: Baal
// Code: 777
// Speed: 66.6
// Wage: 666
// About the Casual typist: 
// Name: Beelzebul
// Code: 888
// Speed: 333
// Wage: 111