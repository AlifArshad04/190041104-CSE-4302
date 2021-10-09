#include <bits/stdc++.h>
using namespace std;

template <typename T, int n>
class my_stack
{
private:
  T array[n];
  int totalElements = 0;

public:
  class EmptyStack
  {
  public:
    string str;
    EmptyStack(string _str) : str(_str) {}
  };

  bool push(T x)
  {
    cout << "total: " << totalElements << endl;
    if (totalElements + 1 >= n)
    {
      cout << "Maximum Size Limit Reached" << endl;
      return false;
    }
    else
    {
      array[totalElements++] = x;
      return true;
    }
  }

  T pop()
  {
    if (totalElements != 0)
    {
      T lastElement = array[--totalElements];
      return lastElement;
    }
    else
    {
      throw EmptyStack("No elements in the stack");
    }
  }

  T peek()
  {
    if (totalElements != 0)
    {
      return array[0];
    }
    else
    {
      cout << "No elements in the stack" << endl;
    }
  }
};

int main()
{
  my_stack<int, 5> stack1;
  stack1.push(1);
  stack1.push(2);
  try
  {
    cout << stack1.pop() << endl;
  }
  catch (my_stack<int, 5>::EmptyStack e)
  {
    cout << e.str << endl;
  }

  stack1.push(3);
  stack1.push(4);
  cout << stack1.peek() << endl;
  stack1.push(5);
  stack1.push(6);
  stack1.push(7);
  // stack1.push(8);
  cout << stack1.peek() << endl;

  my_stack<char, 5> stack2;
  stack2.push('A');
  stack2.push('B');
  cout << stack2.peek() << endl;
  stack2.push('C');
  stack2.push('D');
  try
  {
    cout << stack2.pop() << endl;
  }
  catch (my_stack<char, 5>::EmptyStack e)
  {
    cout << e.str << endl;
  }
  stack2.push('E');
  stack2.push('F');
}