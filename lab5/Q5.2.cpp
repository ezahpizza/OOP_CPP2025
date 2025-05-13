#include<iostream>

using namespace std;

class shape {
    protected:
        double x,y;
    public:
        void get(int a,int b) {
            x=a;
            y=b;
        }

        virtual void display_area() = 0;
};

class rec:public shape {
    public:
        void display_area() {
            cout<<"\nx = "<< x <<", y = " << y <<" ";
            cout<<"\nArea of Rectangle : " << x*y;
        }
};

class tri:public shape {
    public:
        void display_area() {
            cout<<"\nx = "<< x <<", y = " << y <<" ";
            cout<<"\nArea of Triangle : " << 0.5*x*y;
        }
};

int main() {
	shape *ptr;
	rec r1;
	tri t1;

	r1.get(5,3);
	t1.get(6,7);

	ptr=&r1;
	ptr->display_area();

	ptr=&t1;
	ptr->display_area();

	return 0;
}

// Output:

// x = 5, y = 3 
// Area of Rectangle : 15
// x = 6, y = 7 
// Area of Triangle : 21
