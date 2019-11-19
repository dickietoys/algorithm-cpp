#ifndef LARGEST_CONTIGUOUS_SUB_ARRAY_H
#define LARGEST_CONTIGUOUS_SUB_ARRAY_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <vector>
#include <algorithm>

using namespace std;

class LargestContiguousSubArray : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================LargestContiguousSubArray====================" << endl;
    // 3
    vector<int> arr = {10, 12, 11};
    cout << "FindLargest: " << FindLargest(arr) << endl;

    // 2
    arr = {14, 12, 11, 20};
    cout << "FindLargest: " << FindLargest(arr) << endl;

    // 5
    arr = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
    cout << "FindLargest: " << FindLargest(arr) << endl;

    cout << "=================LargestContiguousSubArray====================" << endl;
  }

  int FindLargest(vector<int> &arr)
  {
    int largest = 0;
    int length = arr.size();
    for (int i = 0; i < length; ++i)
    {
      int min = arr[i];
      int max = arr[i];
      for (int j = i + 1; j < length; ++j)
      {
        max = std::max(max, arr[j]);
        min = std::min(min, arr[j]);
        if (max - min == j - i)
        {
          int size = j - i + 1;
          largest = std::max(largest, size);
        }
      }
    }

    return largest;
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
