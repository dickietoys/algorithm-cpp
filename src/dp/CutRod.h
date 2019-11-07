#ifndef CUT_ROD_H_
#define CUT_ROD_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include <testsuit/TestBase.h>

using namespace std;

/*
  切钢条
*/
class CutRod : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================CutRod====================" << endl;
    vector<int> arr = {0, 1, 5, 8, 9, 10, 17, 17, 20};
    int rodSize = 8;
    cout << "BruteResult: " << BruteResult(arr, rodSize) << endl;
    cout << "DpResult: " << DpResult(arr, rodSize) << endl;

    arr = {0, 3, 5, 8, 9, 10, 17, 17, 20};
    rodSize = 8;
    cout << "BruteResult: " << BruteResult(arr, rodSize) << endl;
    cout << "DpResult: " << DpResult(arr, rodSize) << endl;
    cout << "=================CutRod====================" << endl;
  }

  int BruteResult(const vector<int> &arr, int rodSize)
  {
    return BruteResultAux(arr, rodSize);
  }

  int DpResult(const vector<int> &arr, int rodSize)
  {
    return DpResultAux(arr, rodSize);
  }

 private:
  int BruteResultAux(const vector<int> &arr, int rodSize)
  {
    if (rodSize == 0)
    {
      return 0;
    }

    int sum = 0;
    for (int i = 1; i <= rodSize; ++i)
    {
      sum = std::max(arr[i] + BruteResultAux(arr, rodSize - i), sum);
    }

    return sum;
  }

  int DpResultAux(const vector<int> &arr, int rodSize)
  {
    vector<int> bookmark(rodSize + 1, 0);
    bookmark[1] = arr[1];
    for (int i = 2; i <= rodSize; ++i)
    {
      int max = 0;
      for (int j = 1; j <= i; ++j)
      {
        max = std::max(arr[j] + bookmark[i-j], max);
      }
      bookmark[i] = max;
    }

    return bookmark[rodSize];
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
