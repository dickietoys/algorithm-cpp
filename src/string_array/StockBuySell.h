#ifndef STOCK_BUY_SELL_H
#define STOCK_BUY_SELL_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <vector>
#include <algorithm>

using namespace std;

class StockBuySell : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================StockBuySell====================" << endl;
    vector<int> arr = {100, 180, 260, 310, 40, 535, 695};

    cout << "=================StockBuySell====================" << endl;
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
