#ifndef SMALLEST_SUB_ARRAY_WITH_SUM_H
#define SMALLEST_SUB_ARRAY_WITH_SUM_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <vector>
#include <algorithm>

using namespace std;

class SmallestSubArrayWithSum : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================SmallestSubArrayWithSum====================" << endl;
    // 3
    vector<int> arr = {1, 4, 45, 6, 0, 19};
    int sum = 51;
    cout << "FindSmallest: " << FindSmallest(arr, sum) << endl;

    // 1
    arr = {1, 10, 5, 2, 7};
    sum = 9;
    cout << "FindSmallest: " << FindSmallest(arr, sum) << endl;

    // 4
    arr = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    sum = 280;
    cout << "FindSmallest: " << FindSmallest(arr, sum) << endl;

    // Not Possible
    arr = {1, 2, 4};
    sum = 8;
    cout << "FindSmallest: " << FindSmallest(arr, sum) << endl;

    cout << "=================SmallestSubArrayWithSum====================" << endl;
  }

  int FindSmallest(vector<int> &arr, int sum)
  {
    int length = arr.size();
    int min = 0;
    for (int i = 0; i < length; ++i)
    {
      int curSum = arr[i];
      if (curSum > sum)
      {
        min = 1;
      }

      for (int j = i + 1; j < length; ++j)
      {
        curSum += arr[j];
        if (curSum > sum)
        {
          if (min == 0)
          {
            min = j - i + 1;
          }
          else
          {
            min = std::min(min, j - i + 1);
          }
        }
      }
    }

    return min;
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
