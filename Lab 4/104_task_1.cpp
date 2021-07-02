#include <bits/stdc++.h>
#include <string>
using namespace std;
// Task 1
// Define a class “BankAccount” with the following description.
// Each account will have the following information.

// Private members

// The account number.
// The account holder name.
// The account type (Current/ Savings)(assume the data type)
// The current balance.
// The minimum balance (An account has to maintain Minimum Amount, cannot withdraw)
// The class will have the following criteria.
class BankAccount
{
private:
    enum acType
    {
        Current,
        Savings
    };
    static int noOfAccunts;
    int accountNumber;
    string holderName;
    acType accountType;
    double currentBalance;
    double minimumBalance;
    // Public members
    // The member variables value of the object can be assigned during object creation or after the object has been created.
public:
    BankAccount(string _holderName, acType _accountType, double _currentBalance, double _minimumBalance) : accountNumber(++noOfAccunts), holderName(_holderName), accountType(_accountType), currentBalance(_currentBalance), minimumBalance(_minimumBalance)
    {
    }
    BankAccount()
    {
        string tempAcType;
        accountNumber = ++noOfAccunts;
        cout << "Enter name: ";
        cin >> holderName;
        cout << "Enter account type: ";
        cin >> tempAcType;
        if (tempAcType == "current")
        {
            accountType = Current;
        }
        else if (tempAcType == "savings")
        {
            accountType == Savings;
        }
        cout << "Enter current balance: ";
        cin >> currentBalance;
        cout << "Enter Minimum balance: ";
        cin >> minimumBalance;
    }
    // A function to show all the information of a BankAcccout object.
    void display()
    {
        cout << "Account Number: " << accountNumber << '\n';
        cout << "Account Name: " << holderName << '\n';
        if (accountType == Current)
        {
            cout << "Account Type: Current\n";
        }
        else if (accountType == Savings)
        {
            cout << "Account Type: Savings\n";
        }
        cout << "Current balance: " << currentBalance << '\n';
        cout << "Minimum balance: " << minimumBalance << '\n';
    }
    // Function showBalance() (for displaying current balance),
    void showBalance()
    {
        cout << currentBalance;
    }
    // Functions deposit() and withdrawal() of money from an account. Show appropriate messages for invalid amount.
    void deposit(double _amount)
    {
        if (_amount <= 0.0)
        {
            cout << "Invalid amout for diposite\n";
            return;
        }
        currentBalance += _amount;
    }
    void withdrawal(double _amount)
    {
        if (currentBalance - _amount < minimumBalance || _amount <= 0.0)
        {
            cout << "Invalid amout for withdrawal\n";
            return;
        }
        currentBalance -= _amount;
    }
    // Function giveInterst() will deposit net interest to the account.   Default interest is 3 percent of current balance but it might be different. A fixed 10% Source Tax will be deducted from the incurred interest.
    void giveInterst(double _rate = 3)
    {
        double interest = currentBalance * _rate / 100;
        deposit(interest);
        double tax = interest * 0.9;
        withdrawal(tax);
    }
    // When the BankAccount object is destroyed display a message like : Account of Mr. X with account no 1234 is destroyed with a balance BDT 5000
    ~BankAccount()
    {
        cout << "Account of " << holderName << " with account no " << accountNumber << " is destroyed with a balance BDT " << currentBalance << '\n';
    }
};

int BankAccount::noOfAccunts = 0;

main()
{
    BankAccount ac1;
    ac1.deposit(300);
    ac1.withdrawal(1000);
    ac1.display();
    ac1.giveInterst();
    ac1.showBalance();
    ac1.giveInterst(7);
    ac1.showBalance();

    return 0;
}