#ifndef COUNT_TRIPLETS_SUM_SMALLER_H
#define COUNT_TRIPLETS_SUM_SMALLER_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <vector>
#include <algorithm>

using namespace std;

class CountTripletsSumSmaller : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================CountTripletsSumSmaller====================" << endl;
    vector<int> arr = {-2, 0, 1, 3};
    int sum = 2;
    int count = 0;
    // 2
    count = CountSmaller(arr, sum);
    cout << "count: " << count << endl;

    arr = {5, 1, 3, 4, 7};
    sum = 12;
    // 4
    count = CountSmaller(arr, sum);
    cout << "count: " << count << endl;
    cout << "=================CountTripletsSumSmaller====================" << endl;
  }

  int CountSmaller(vector<int> &arr, int sum)
  {
    std::sort(arr.begin(), arr.end());
    int length = arr.size();
    int count = 0;
    for (int i = 0; i < length; ++i)
    {
      int j = i + 1;
      int k = length - 1;
      while (j < k)
      {
        if (arr[i] + arr[j] + arr[k] >= sum)
        {
          --k;
        }
        else
        {
          count += k - j;
          ++j;
        }
      }
    }

    return count;
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
