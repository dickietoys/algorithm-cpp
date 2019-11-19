#ifndef PYTHAGOREAN_TRIPLET_H
#define PYTHAGOREAN_TRIPLET_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <vector>
#include <algorithm>

using namespace std;

class PythagoreanTriplet : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================PythagoreanTriplet====================" << endl;
    vector<int> arr = {3, 1, 4, 6, 5};
    cout << Find(arr) << endl;
    arr = {10, 4, 6, 12, 5};
    cout << Find(arr) << endl;
    cout << "=================PythagoreanTriplet====================" << endl;
  }

  int Find(vector<int> &arr)
  {
    for (size_t i = 0; i < arr.size(); ++i)
    {
      arr[i] *= arr[i];
    }

    std::sort(arr.begin(), arr.end());

    for (size_t i = arr.size() - 1; i >= 2; --i)
    {
      int j = 0;
      int k = i - 1;
      while (j < k)
      {
        if (arr[j] + arr[k] == arr[i])
        {
          return true;
        }
        else if (arr[j] + arr[k] > arr[i])
        {
          --k;
        }
        else
        {
          ++j;
        }
      }
    }

    return false;
  }

  void Show(const vector<int> &arr)
  {
    for (size_t i = 0; i < arr.size(); ++i)
    {
      cout << arr[i] << ", ";
    }

    cout << endl;
  }
};

#endif
