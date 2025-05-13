#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

class account{

    protected:
        char cust_name[20];
        int accno;
        char type;
        int bal;

    public:
        account() {
            strcpy(cust_name," ");
            accno=0;
            type=' ';
            bal=0;
        }
        void input() {
            cout<<"Enter Name: ";cin>>cust_name;
            cout<<"Enter Account no.: ";cin>>accno;
            fflush(stdin);
            cout<<"Enter Type: "; cin>>type;
            fflush(stdin);
            cout<<"Enter Balance: ";cin>>bal;
        }
        void display() {
                cout<<"\n Customer Name: "<<cust_name;
                cout<<"\n Account Number: "<<accno;
                cout<<"\n Type: "<<type;
                cout<<"\n Balance: "<<bal;
        }
        void deposit() {
                int amt;
                cout<<"\n Enter the amount to deposit.";
                cin>>amt;
                bal += amt;
        }
};
class sav_acct:public account{
    int inter;
    public:
        int comp_int(){
            int time1,rate1;
            rate1=10;
            cout<<"\n Enter time";cin>>time1;
            inter=bal*pow(1+rate1/100.0,time1)-bal;
            return inter;
        }

        void update_bal(){
            bal+=comp_int();
        }

        void withdrawal(){
            int amt;
            cout<<"\n Enter amount to withdrawnL: ";
            cin>>amt;
            if(bal>=amt){
                bal-=amt;
            }
            else{
                cout<<"\n The amount cannot be withdrawn.";
            }
        }
};

class cur_acct:public account{
    int chq_bk;
    int penal;

    public:
        int min_bal(){
            int ret1=1;
            if(bal<=500){
                penal=50;
                bal-=penal;
                ret1=0;
            }
            else{
                cout<<"\n No penality imposed.";
            }
            return ret1;
        }
        void withdrawal(){
            int amt;
            cout<<"\n Enter the amount to withdrawn: ";
            cin>>amt;
            int k=min_bal();
            if(k==1){
                if(bal>=amt)
                bal=bal-amt;
            }
            else{
                cout<<"\n The amount cannot be withdrawn.";
            }
        }
};

int main(){
    cur_acct c1;
    sav_acct s1;
    c1.input();
    c1.display();
    c1.deposit();
    c1.display();
    c1.withdrawal();
    c1.display();
    s1.input();
    s1.display();
    s1.deposit();
    s1.display();
    s1.withdrawal();
    s1.display();
    
    return 0;
}