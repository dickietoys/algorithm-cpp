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
    int max = FindMax(arr);
    cout << "FindMax: " << max << endl;
    cout << "=================StockBuySell====================" << endl;
  }

  int FindMax(vector<int> &arr)
  {
    return FindMaxAux(arr, 0, 0, false);
  }

  void Show(const vector<int> &arr)
  {
    for (size_t i = 0; i < arr.size(); ++i)
    {
      cout << arr[i] << ", ";
    }

    cout << endl;
  }
 private:
  int FindMaxAux(vector<int> &arr, int pos, int sum, bool buyed)
  {
    int length = arr.size();
    if (pos == length)
    {
      return sum;
    }

    int max = 0;
    for (int i = pos; i < length; ++i)
    {
      if (buyed)
      {
        max = std::max({FindMaxAux(arr, i + 1, sum, buyed),
              FindMaxAux(arr, i + 1, sum + arr[i], !buyed),
              max});
      }
      else
      {
        max = std::max({max,
              FindMaxAux(arr, i + 1, sum, buyed),
              FindMaxAux(arr, i + 1, sum - arr[i], !buyed)});
      }
    }

    return max;
  }
};

#endif
