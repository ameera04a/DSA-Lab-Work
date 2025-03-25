#include<iostream>
using namespace std;

class Shape{
    public:
    virtual double area()=0;
};
class Circle: public Shape{
    double radius;
    public:
    Circle(int r):radius(r){}
    double area(){
        return 2*3.1416*radius;
    }
};
class Rectangle: public Shape{
    double length;
    double width;
    public:
    Rectangle(int l, int w):length(l), width(w){}
    double area(){
        return width*length;
    }
};
int main(){
    Circle c (3);
    Rectangle r (2, 3);
    cout<<"Circle area: "<<c.area();
    cout<<"\nRectangle area: "<<r.area();

    return 0;
}