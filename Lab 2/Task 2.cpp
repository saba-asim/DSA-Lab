#include <iostream>
using namespace std;
class employee
{
public:
    virtual double calculatesalary()  = 0;
    virtual ~employee() 
    {
        cout << "Destructor is called" << endl;
    }
};
class fulltimeemployee : public employee 
{
private:
    double fixedsalary;
public:
    fulltimeemployee(double newfixedsalary)
    {
        fixedsalary = newfixedsalary;
    }
    double calculatesalary()  override
    {
        return fixedsalary;
    }
};
class parttimeemployee : public employee
{
private:
    double hourwork;
    double hourrate;
public:
    parttimeemployee(double newhours, double newrate)
    {
        hourwork= newhours;
        hourrate = newrate;
    }
    double calculatesalary()  override
    {
        return hourwork * hourrate;
    }
};
int main()
{
    fulltimeemployee ft(20000);
    parttimeemployee pt(10, 5);
    cout << "The salary of full time employee is: " << ft.calculatesalary() << endl;
    cout << "The salary of part time employee is: " << pt.calculatesalary() << endl;
    return 0;
}

