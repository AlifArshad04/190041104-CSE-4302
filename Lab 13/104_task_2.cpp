#include <iostream>
using namespace std;

double g = 9.81;

namespace my_namespace
{
  double g = 10;
}

int main()
{
  cout << g << " " << my_namespace::g << "\n";
}