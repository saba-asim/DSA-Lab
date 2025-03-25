#include <iostream>
using namespace std;
class shape
{
public:
    virtual double area() = 0; 
    virtual ~shape() 
    {
        cout << "Destructor is called" << endl;
    }
};
class circle : public shape 
{
private:
    double radius;
public:
    circle()
    {
        radius = 0;
    }
    circle(double r) 
    {
        radius = r;
    }
    double area() override
    {
        return 3.14 * radius * radius;
    }
};
class rectangle : public shape
{
private:
    double length;
    double width;
public:
    rectangle()
    {
        length = 0;
        width = 0;
    }
    rectangle(double newlength, double newwidth)
    {
        length = newlength;
        width = newwidth;
    }
    double area() override
    {
        return length * width;
    }
};
int main() 
{
    double r;
    cout << "Enter the radius of circle:";
    cin >> r;
    circle c(r);
    cout << "Area of Circle: " << c.area() << endl;
    double l1;
    double w1;
    cout << "Enter the length of rectangle:";
    cin >> l1;
    cout << "Enter the width of rectangle:";
    cin >> w1;
    rectangle rec(l1, w1);
    cout << "Area of Rectangle: " << rec.area() << endl;
    return 0;
}
