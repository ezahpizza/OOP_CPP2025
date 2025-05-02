#include <iostream>
using namespace std;

class Account {
    int act_no; string
    cust_name;
public:
    void getdata() {
        cout<<"Enter Accout number and Customer name:"<<endl;
        cin>>act_no>>cust_name;
    }
    void show () {
        cout<<"Account Number:"<<act_no<<endl;
        cout<<"Customer Name:"<<cust_name<<endl;
    }
};

class SB_Act: public Account {
    float roi;
public:
    void getdata() {
        Account::getdata();
        cout<<"Enter Rate of Interest"<<endl;
        cin>>roi;
    }
    void show () {
        cout<<"***** SAVINGS ACCOUNT********"<<endl;
        Account:: show ();
        cout<<"Rate of Interest:"<<roi<<endl;
    }
};

class Current_Act: public Account {
    float roi;
public:
    void getdata() {
        Account::getdata();
        cout<<"Enter Rate of Interest"<<endl;
        cin>>roi;
    }
    void show () {
        cout<<"***** CURRENT ACCOUNT********"<<endl;
        Account:: show ();
        cout<<"Rate of Interest:"<<roi<<endl;
    }
};

int main() {
    SB_Act s;
    s.getdata();
    s. show ();
    
    Current_Act c;
    c.getdata();
    c. show ();
    return 0;
}