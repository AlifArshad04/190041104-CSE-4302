#include <bits/stdc++.h>
using namespace std;

const int LEN = 32;
const int MAXAC = 100;
enum account_type
{
  tchecking,
  tsaving
};

class Account
{
private:
  char holder[LEN];
  static int n;
  static Account *arrap[];

protected:
  double balance;

public:
  virtual void getdata()
  {
    cin.ignore(10, '\n');
    cout << " Enter holder name:";
    cin >> holder;
    cout << " Enter balance:";
    cin >> balance;
  }
  virtual void putdata()
  {
    cout << "\n Holder name:" << holder;
    cout << "\n Balance : " << balance;
  }
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

  virtual account_type getType();
  static void add();
  static void display();
  static void read();
  static void write();
};

int Account::n;
Account *Account::arrap[MAXAC];

class Checking : public Account
{
private:
  double check_rate;

public:
  void getdata()
  {
    Account::getdata();
    cout << " Enter Check rate: ";
    cin >> check_rate;
  }
  void putdata()
  {
    Account::putdata();
    cout << "\n Check rate: " << check_rate;
  }
  void withdraw(double w)
  {
    w = (check_rate / 100) * balance - w;
    if (balance - w < 0)
      cerr << "Cannot withdraw this amount\n";
    else
      balance -= w;
  }
};
class Saving : public Account
{
private:
  double interest;

public:
  void getdata()
  {
    Account::getdata();
    cout << " Enter interest rate: ";
    cin >> interest;
  }
  void putdata()
  {
    Account::putdata();
    cout << "\n Interest rate: " << interest;
  }
  void deposit(double d)
  {
    d += (interest / 100) * balance;
    if (balance > 0)
      balance += d;
    else
      cerr << "Illegal deposit\n";
  }
};

void Account::add()
{
  char ch;
  cout << "'c' to add a Checking "
          "\n's' to add a Saving "
          "\nEnter selection : ";
  cin >> ch;
  switch (ch)
  { //create specified Account type
  case 'c':
    arrap[n] = new Checking;
    break;
  case 's':
    arrap[n] = new Saving;
    break;
  default:
    cout << "\nUnknown Account type\n ";
    return;
  }
  arrap[n++]->getdata(); //get Account data from user
}
//--------------------------------------------------------------
//display all Accounts
void Account::display()
{
  for (int j = 0; j < n; j++)
  {
    cout << (j + 1);             //display number
    switch (arrap[j]->getType()) //display type
    {
    case tchecking:
      cout << ".Type : Checking ";
      break;
    case tsaving:
      cout << ".Type : Saving ";
      break;
    default:
      cout << ".Unknown type ";
    }
    arrap[j]->putdata(); //display Account data
    cout << endl;
  }
}
//--------------------------------------------------------------
//return the type of this object
account_type Account::getType()
{
  if (typeid(*this) == typeid(Checking))
    return tchecking;
  else if (typeid(*this) == typeid(Saving))
    return tsaving;
  else
  {
    cerr << "\nBad Account type ";
    exit(1);
  }
  return tchecking;
}
//--------------------------------------------------------------
//write all current memory objects to file
void Account::write()
{
  int size;
  cout << "Writing " << n << " Accounts.\n ";
  ofstream ouf;       //open ofstream in binary
  account_type etype; //type of each Account object
  ouf.open("ACCOUNT.DAT", ios::trunc | ios::binary);
  if (!ouf)
  {
    cout << "\nCan't open file\n ";
    return;
  }
  for (int j = 0; j < n; j++) //for every Account object
  {                           //get its type
    etype = arrap[j]->getType();
    //write type to file
    ouf.write((char *)&etype, sizeof(etype));
    switch (etype) //find its size
    {
    case tchecking:
      size = sizeof(Checking);
      break;
    case tsaving:
      size = sizeof(Saving);
      break;
    } //write Account object to file
    ouf.write((char *)(arrap[j]), size);
    if (!ouf)
    {
      cout << "\nCan't write to file\n ";
      return;
    }
  }
}
//--------------------------------------------------------------
//read data for all Accounts from file into memory
void Account::read()
{
  int size;           //size of Account object
  account_type etype; //type of Account
  ifstream inf;       //open ifstream in binary
  inf.open("ACCOUNT.DAT", ios::binary);
  if (!inf)
  {
    cout << "\nCan't open file\n ";
    return;
  }
  n = 0; //no Accounts in memory yet
  while (true)
  { //read type of next Account
    inf.read((char *)&etype, sizeof(etype));
    if (inf.eof()) //quit loop on eof
      break;
    if (!inf) //error reading type
    {
      cout << "\nCan't read type from file\n ";
      return;
    }
    switch (etype)
    {               //make new Account
    case tchecking: //of correct type
      arrap[n] = new Checking;
      size = sizeof(Checking);
      break;
    case tsaving:
      arrap[n] = new Saving;
      size = sizeof(Saving);
      break;
    default:
      cout << "\nUnknown type in file\n ";
      return;
    } //read data from file into it
    inf.read((char *)arrap[n], size);
    if (!inf) //error but not eof
    {
      cout << "\nCan't read data from file\n ";
      return;
    }
    n++; //count Account
  }
  cout << "Reading " << n << " Accounts\n";
}

int main()
{
  char ch;
  while (true)
  {
    cout << "'a' -- add data for an account"
            "\n'd' -- display data for all accounts"
            "\n'w' -- write all account data to file"
            "\n'r' -- read all account data from file"
            "\n'x' -- exit"
            "\nEnter selection: ";
    cin >> ch;
    switch (ch)
    {
    case 'a':
      Account::add();
      break;
    case 'd':
      Account::display();
      break;
    case 'w':
      Account::write();
      break;
    case 'r':
      Account::read();
      break;
    case 'x':
      exit(0);
      return 0;
    default:
      cout << "\nUnknown command ";
    }
  }
  return 0;
}
