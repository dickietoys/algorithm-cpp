#ifndef CONVERT_ARRAY_INFO_ZIG_ZAG_H
#define CONVERT_ARRAY_INFO_ZIG_ZAG_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <vector>
#include <algorithm>

using namespace std;

class ConvertArrayInfoZigZag : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================ConvertArrayInfoZigZag====================" << endl;
    vector<int> arr = {4, 3, 7, 8, 6, 2, 1};
    cout << "before convert: ";
    Show(arr);
    ConvertZigZag(arr);
    cout << "after convert: ";
    Show(arr);

    arr = {1, 4, 3, 2};
    cout << "before convert: ";
    Show(arr);
    ConvertZigZag(arr);
    cout << "after convert: ";
    Show(arr);
    cout << "=================ConvertArrayInfoZigZag====================" << endl;
  }

  void ConvertZigZag(vector<int> &arr)
  {
    std::sort(arr.begin(), arr.end());
    for (size_t i = 1; i < arr.size() - 1;)
    {
      std::swap(arr[i], arr[i+1]);
      i += 2;
    }
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
