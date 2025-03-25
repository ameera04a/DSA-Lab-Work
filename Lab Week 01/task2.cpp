#include<iostream>
using namespace std;

class Employee{
    public:
    virtual double calculateSalary()=0;
};
class FullTimeEmployee: public Employee{
    double salary;
    public:
    FullTimeEmployee(int s):salary(s){}
    double calculateSalary(){
        return salary;
    }
};
class PartTimeEmployee: public Employee{
    int hrsWorked;
    double hourlyRate;
    public:
    PartTimeEmployee(int hw, int hr):hrsWorked(hw), hourlyRate(hr){}
    double calculateSalary(){
        return hrsWorked*hourlyRate;
    }
};
int main(){
    FullTimeEmployee e1 (30000);
    PartTimeEmployee e2 (5, 350);
    cout<<"FullTimeEmployee salary: "<<e1.calculateSalary();
    cout<<"\nPartTimeEmployee salary: "<<e2.calculateSalary();

    return 0;
}