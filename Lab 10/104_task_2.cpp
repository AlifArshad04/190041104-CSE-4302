#include "iostream"
using namespace std;

class People
{
private:
    string *name;

    // People(People &p);
    // void operator=(People &p);

public:
    People()
    {
        name = new string;
        *name = "";
    }

    People(People &p)
    {
        name = new string;
        *name = *p.name;
    }

    void operator=(People &p)
    {
        name = new string;
        *name = *p.name;
    }

    void setName(string n)
    {
        *name = n;
    }

    string getName()
    {
        return *name;
    }
};

int main()
{
    People P1;
    P1.setName("alif");

    People P2 = P1;
    P1.setName("labib");

    cout << "P1 name: " << P1.getName() << "\n";
    cout << "P2 name: " << P2.getName() << "\n";

    People P3(P2);
    P2.setName("reaz");

    cout << "P2 name: " << P2.getName() << "\n";
    cout << "P3 name: " << P3.getName() << "\n";

    return 0;
}