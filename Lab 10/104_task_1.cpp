#include <iostream>
using namespace std;

class Account
{
protected:
    double balance;

public:
    Account(double _balance) : balance(_balance) {}
    virtual void withdraw(double w)
    {
        if (balance - w < 0)
            cerr << "Cannot withdraw this amount\n";
        else
            balance -= w;
    }
    virtual void deposit(double d)
    {
        if (balance > 0)
            balance += d;
        else
            cerr << "Illegal deposit\n";
    }
    virtual void display() = 0;
};
class Checking : public Account
{
private:
    double check_rate;

public:
    Checking(double _balance, double _check) : Account(_balance)
    {
        check_rate = _check;
    }
    void withdraw(double w)
    {
        w = (check_rate / 100) * balance - w;
        if (balance - w < 0)
            cerr << "Cannot withdraw this amount\n";
        else
            balance -= w;
    }
    void display()
    {
        cout << "Checking Account- " << balance << '\n';
    }
};
class Saving : public Account
{
private:
    double interest;

public:
    Saving(double _balance, double _interest) : Account(_balance)
    {
        interest = _interest;
    }
    void deposit(double d)
    {
        d += (interest / 100) * balance;
        if (balance > 0)
            balance += d;
        else
            cerr << "Illegal deposit\n";
    }
    void display()
    {
        cout << "Savings Account- " << balance << '\n';
    }
};
int main()
{
    Account *a[10];
    a[1] = new Saving(5000, 5);
    a[2] = new Checking(15000, 15);

    a[1]->display();
    a[2]->display();

    a[1]->deposit(50000);
    a[1]->display();
    a[2]->withdraw(1500);
    a[2]->display();
}
