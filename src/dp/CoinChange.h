#ifndef COIN_CHANGE_H_
#define COIN_CHANGE_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include <testsuit/TestBase.h>

using namespace std;

/*
  给定总额n，和不等面值的硬币，数量不限，一共有多少组合方式
*/
class CoinChange : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================CoinChange====================" << endl;
    vector<int> arr = {1, 2, 3};
    int n = 4;
    // result 4
    cout << "BruteResult: " << BruteResult(arr, n) << endl;
    cout << "DpResult: " << DpResult(arr, n) << endl;

    arr = {2, 5, 3, 6};
    n = 10;
    // result 5
    cout << "BruteResult: " << BruteResult(arr, n) << endl;
    cout << "DpResult: " << DpResult(arr, n) << endl;
    cout << "=================CoinChange====================" << endl;
  }

  int BruteResult(const vector<int> &arr, int n)
  {
    return BruteResultAux(arr, arr.size() - 1, n);
  }

  int DpResult(const vector<int> &arr, int n)
  {
    return DpResultAux(arr, n);
  }

 private:
  int BruteResultAux(const vector<int> &arr, int pos, int n)
  {
    if (n == 0)
    {
      return 1;
    }

    if (n < 0)
    {
      return 0;
    }

    if (pos < 0 && n > 0)
    {
      return 0;
    }

    return BruteResultAux(arr, pos, n - arr[pos]) + BruteResultAux(arr, pos - 1, n);
  }

  int DpResultAux(const vector<int> &arr, int n)
  {
    vector<vector<int>> bookmark(arr.size() + 1, vector<int>(n + 1, 0));
    for (size_t i = 1; i <= arr.size(); ++i)
    {
      bookmark[i][0] += 1;
    }

    for (size_t i = 1; i <= arr.size(); ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        if (j-arr[i-1] >= 0)
        {
          bookmark[i][j] = bookmark[i-1][j] + bookmark[i][j-arr[i-1]];
        }
        else
        {
          bookmark[i][j] = bookmark[i-1][j];
        }
      }
    }

    return bookmark[arr.size()][n];
  }

  void showBookmark(const vector<vector<int>> &bookmark)
  {
    cout << endl;
    for (size_t i = 0; i < bookmark.size(); ++i)
    {
      for (size_t j = 0; j < bookmark[i].size(); ++j)
      {
        cout << bookmark[i][j] << ", ";
      }
      cout << endl;
    }
  }
};

#endif
