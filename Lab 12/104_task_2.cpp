#include <bits/stdc++.h>
using namespace std;

template <typename T>
T amax(T *arr, int size, int n)
{
  T temp[size];
  copy(arr, arr + size, temp);
  sort(temp, temp + size);
  return temp[size - n];
}

int main()
{
  int arr1[5] = {1, 2, 3, 4, 5};
  cout << amax(arr1, 5, 3) << endl;

  double arr2[5] = {3.9, 1.6, 0.7, 2.4, 1.5};
  cout << amax(arr2, 5, 2) << endl;

  return 0;
}