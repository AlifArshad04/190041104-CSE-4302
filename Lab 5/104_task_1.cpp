#include <iostream>
#include <algorithm>
using namespace std;

// Create a class named “Counter”. An object of Counter class keeps track of count. The object also stores the value of increment steps. For example if the increment step is 5 count will be incremented by 5 each time increment is done. To do these, declare necessary private member data.
// Note that there should NOT be any public methods to assign a value to count.
class Counter
{
private:
    int count;
    int step;

public:
    Counter() : count(0), step(1) {}
    Counter(int _c, int _s) : count(_c), step(_s) {}
    // Implement the following public member functions (task of the function is written after a hyphen):

    // void setIncrementStep(int step_val) - it sets the value of Increment Step in the appropriate member data. The default value is 1. Do not assign a negative value.
    void setIncrementStep(int step_val) { step = step_val; }

    // int getCount() - it returns the current count value.
    int getCount() { return count; }

    // void increment() - it increments the count by increment step. For example : if the current count is 4 and increment step value is 2 then executing the function will update the count to 6.
    void increment() { count += step; }

    // void resetCount() - it resets the value of count to 0.
    void resetCount() { count = 0; }
    // Write necessary member or non member functions to achieve following functionalities.

    // Assume c1,c2,c3 are Count objects. c1 = c2 + c3; After this statement the count value of c1 will be the summation of count of c2 and c3. No changes to c2 and c3. The step value will be the minimum of c2 and c3.
    Counter operator+(Counter &_ro) const { return Counter(count + _ro.count, min(step, _ro.step)); }

    // Assume var is an int variable. c1 = c2 + var; c1 = var + c2; After these statements the count of c1 will be the summation of count of c2 and var. The step value will be the same as c2. No changes to c2.
    Counter operator+(int _var) { return Counter(count + _var, step); }
    friend Counter operator+(int _var, Counter &_ro);

    // c1+=c2; No changes to c2.
    void operator+=(const Counter &_ro) { count += _ro.count; }

    // c1 = c2++; c1= ++c2; functions similar to increment() function. The return policy should follow conventional rule.
    Counter operator++() { return Counter((count += step), step); }
    Counter operator++(int)
    {
        Counter temp = *this;
        count += step;
        return temp;
    }
};

Counter operator+(int _var, Counter &_ro)
{
    return Counter(_var + _ro.getCount(), _ro.step);
}

int main()
{
    Counter c2, c3;
    c2.setIncrementStep(3);
    c2.increment();
    c3.increment();
    c3.increment();

    Counter c1;
    c1 = c2 + c3;
    cout << c1.getCount() << '\n';
    c1.increment();
    cout << c1.getCount() << '\n';
    cout << "c1 = 5 + c2 = " << (5 + c2).getCount() << '\n';
    cout << "c1 = c2 + 5 = " << (c2 + 5).getCount() << '\n';

    Counter c4(0, 5);
    cout << "++c1 = " << (++c4).getCount() << '\n';
    cout << "c1++ = " << (c4++).getCount() << '\n';
    cout << "c1 = " << c4.getCount() << '\n';

    return 0;
}