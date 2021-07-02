#include <iostream>
#include <string>
using namespace std;
// Task 2
// Define a class in C++ with following description:
class Employee
{
    // Private Members:
private:
    // A data member EmpName of type String
    // A data member ID of type Integer
    // A data member Age of type integer
    // A data member Salary of type float
    // A member function getStatus() to return the status of an employee on the basis of the following criteria
    enum stats
    {
        Low,
        Moderate,
        High
    };
    static int noOfEmployee;
    string EmpName;
    int ID;
    int age;
    float Salary;
    stats getStatus()
    {
        if (age <= 25)
        {
            if (Salary <= 20000)
            {
                return Low;
            }
            else
            {
                return Moderate;
            }
        }
        else
        {
            if (Salary <= 21000)
            {
                return Low;
            }
            else if (Salary <= 60000)
            {
                return Moderate;
            }
            else
            {
                return High;
            }
        }
    }

    // Public Members:
public:
    // A function FeedInfo(), to allow the user to enter information of an employee like EmpName, ID, Salary.
    Employee() : ID(++noOfEmployee) {}
    void FeedInfo()
    {
        cout << "Enter Name: ";
        cin >> EmpName;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Salary: ";
        cin >> Salary;
    }
    // A function ShowInfo(), to allow the user to view the content of all the data members. At the end it should display the status of an employee (Low Salaried Person, Moderate Salaried Person, High Salaried Person).
    void ShowInfo()
    {
        cout << "ID: " << ID << '\n';
        cout << "Name: " << EmpName << '\n';
        cout << "Age: " << age << '\n';
        cout << "Salary: " << Salary << '\n';
        cout << "Stasus: ";
        stats tempStat = this->getStatus();
        if (tempStat == Low)
        {
            cout << "Low Salaried Person\n";
        }
        else if (tempStat == Moderate)
        {
            cout << "Moderate Salaried Person\n";
        }
        else if (tempStat == High)
        {
            cout << "High Salaried Person\n";
        }
    }
};

int Employee::noOfEmployee = 0;

int main()
{
    Employee emp1;

    emp1.FeedInfo();
    emp1.ShowInfo();

    return 0;
}