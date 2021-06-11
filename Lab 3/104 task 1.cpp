#include <iostream>

using namespace std;

class RationalNumber
{
private:
    int numerator;
    int denominator;

public:
    RationalNumber() : numerator(0), denominator(1)
    {
    }

    void assign(int _numerator, int _denominator)
    {
        if (_denominator == 0)
        {
            cout << "Invalid denominator!\n";
            return;
        }
        numerator = _numerator;
        denominator = _denominator;
    }

    double convert()
    {
        return (double)numerator / denominator;
    }

    void invert()
    {
        if (numerator == 0)
        {
            cout << "Denominator can't be zero!\n";
            return;
        }
        swap(numerator, denominator);
    }

    void print()
    {
        cout << "The Rational Number is ";
        if (numerator == 0)
        {
            cout << "0\n";
        }
        else
        {
            cout << numerator << "/" << denominator << '\n';
        }
    }
};

int main()
{
    RationalNumber number;

    number.assign(3, 2);
    number.print();

    cout << number.convert() << '\n';

    number.invert();
    number.print();

    return 0;
}