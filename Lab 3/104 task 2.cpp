#include <iostream>
#include <cstring>

using namespace std;

class Medicine
{
private:
    char name[100];
    char genericName[100];
    double discountPercent;
    double unitPrice;

public:
    Medicine() : name(""), genericName(""), discountPercent(5.0), unitPrice(0.0)
    {
    }

    void assignName(char _name[], char _genericName[])
    {
        strcpy(name, _name);
        strcpy(genericName, _genericName);
    }

    void assignPrice(double _price)
    {
        if (_price < 0)
        {
            cout << "Can't enter non-negative price!\n";
        }
        else
        {
            unitPrice = _price;
        }
    }

    void setDiscountPercent(double _percent)
    {
        if (_percent < 0 or _percent > 45)
        {
            cout << "Discount percent is outside range!\n";
        }
        else
        {
            discountPercent = _percent;
        }
    }

    double getSellingPrice(int _nos)
    {
        return _nos * unitPrice * (1.0 - discountPercent / 100.0);
    }

    void display()
    {
        cout << name << " (" << genericName << ") has a unit price of BDT " << unitPrice << ". Current discount " << discountPercent << "%\n";
    }
};

int main()
{
    char napa[] = "Napa";
    char paracetamol[] = "Paracetamol";

    Medicine med;

    med.assignName(napa, paracetamol);
    med.display();

    med.assignPrice(0.8);
    med.display();

    med.setDiscountPercent(15.0);
    med.display();

    cout << med.getSellingPrice(10) << '\n';

    med.display();

    return 0;
}