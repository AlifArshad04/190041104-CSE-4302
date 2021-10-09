#include <bits/stdc++.h>
using namespace std;

int main()
{
  int arr[5];
  set<int> st;
  vector<int> vect(10);

  for (int i = 1; i <= 10; ++i)
  {
    if (i & 1)
      st.insert(i);
    else
      arr[(i - 1) / 2] = i;
  }

  merge(arr, arr + 5, st.begin(), st.end(), vect.begin());

  for (int i = 0; i < 10; ++i)
  {
    cout << vect[i] << " ";
  }
}