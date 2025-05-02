#include <iostream>
using namespace std;

class Publisher {
    string pname;
    string place;
public:
    void getdata() {
        cout<<"Enter name and place of publisher:"<<endl;
        cin>>pname>>place;
    }
    void show () {
        cout<<"Publisher Name:"<<pname<<endl;
        cout<<"Place:"<<place<<endl;
    }
};
class Author {
    string aname;
    public:
        void getdata() {
        cout<<"Enter Author name:"<<endl; 
        cin>>aname;
    }
    void show () {
        cout<<"Author Name:"<<aname<<endl;
    }
};

class Book:public Publisher, public Author {
    string title;
    float price;
    int pages;
public:
    void getdata() {
        Publisher::getdata();
        Author::getdata();
        cout<<"Enter Book Title, Price and No. of pages"<<endl;
        cin>>title>>price>>pages;
    }
    void show() {
        Publisher:: show ();
        Author:: show ();
        cout<<"Title:"<<title<<endl;
        cout<<"Price:"<<price<<endl;
        cout<<"No. of Pages:"<<pages<<endl;
    }
};

int main() {
    Book b;
    b.getdata();
    b.show();
    return 0;
}
