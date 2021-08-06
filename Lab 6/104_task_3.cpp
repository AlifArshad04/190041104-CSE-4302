#include <iostream>
#include <algorithm>
using namespace std;

// Your task is to write a rational number class. Rational numbers can be expressed as a fraction p/q where p and q are each whole numbers and q does not equal 0. The member variables that represent the numerator and denominator should be integers and private to the class.
class rational_number
{
private:
    int numerator;
    int denominator;

    // Include member functions for this class that does at least the following:
    // - Provide a private member error function that is called when the denominator fraction is ever set to 0.
    // This function should both print an appropriate error message on the screen and set both the numerator and the denominator of the current fraction to zero (yes, this is illegal, but you can catch errors
    // this way).
    bool error();

public:
    rational_number(int _numerator = 1, int _denominator = 1)
    {
        if (!error())
        {
            numerator = _numerator;
            denominator = _denominator;
        }
    }
    ~rational_number() {}

    // - Provide two public member accessor functions for the numerator and denominator. Follow the convention that the names of accessor functions begin with "get".
    int getNumerator() { return numerator; }
    int getDenominator() { return denominator; }

    // - Provide two public member mutator functions that can change the value of the numerator and denominator
    // of the current fraction respectively. Follow the convention that the names of mutator functions begin
    // with "set".
    void setNumerator(int _n) { numerator = _n; }
    void setDenominator(int _d) { denominator = _d; }

    // - Provide a public member function that returns a double that is the result of converting the current fraction to a decimal number.
    double fraction();

    // - Overload the addition "+" operator that can be called to add two fractions.
    rational_number operator+(rational_number r2);

    // - Overload the subtraction "-" operator that can be called to subtract two fractions.
    rational_number operator-(rational_number r2);

    // - Overload the multiplication "*" operator that can be called to multiply two fractions.
    rational_number operator*(rational_number r2)
    {
        return rational_number(numerator * r2.numerator, denominator * r2.denominator);
    }

    // - Overload the division "/" operator that can be called to divide two fractions.
    rational_number operator/(rational_number r2)
    {
        return rational_number(numerator * r2.denominator, denominator * r2.numerator);
    }
};

int lcm(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}

bool rational_number::error()
{
    if (denominator == 0)
    {
        cout << "Denominator can't be zero!\n";
        numerator = 0;
        denominator = 0;
        return true;
    }
    else
        return false;
}

double rational_number::fraction()
{
    if (!error())
    {
        double res = (double)numerator / (double)denominator;
        return res;
    }
    return 0;
}

rational_number rational_number::operator+(rational_number r2)
{
    int l = lcm(denominator, r2.denominator);
    int sum = (numerator * l / denominator) + (r2.numerator * l / r2.denominator);

    return rational_number(sum / __gcd(sum, l), l / __gcd(sum, l));
}

rational_number rational_number::operator-(rational_number r2)
{
    int l = lcm(denominator, r2.denominator);
    int a = (numerator * l / denominator), b = ((r2.numerator * l) / (r2.denominator));
    int sum = a - b;
    return rational_number(sum / __gcd(sum, l), l / __gcd(sum, l));
}

int main()
{
    rational_number r1(6, 2), r2(4, 5);
    r1 = r1 - r2;
    cout << r1.getNumerator() << ' ' << r1.getDenominator() << ' ';
}