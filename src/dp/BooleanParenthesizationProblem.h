#ifndef BOOLEAN_PARENTHESIZATION_PROBLEM_H_
#define BOOLEAN_PARENTHESIZATION_PROBLEM_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include <testsuit/TestBase.h>

using namespace std;

/*
  有n个(偶数)硬笔，价值不等，每次只能取第一个或最后一个。
  先选如何保证最大收益

  operation 0 |, 1 &, 2 ^
*/
class BooleanParenthesizationProblem : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================BooleanParenthesizationProblem====================" << endl;
    vector<bool> arr = {true, false, true};
    cout << "BruteResult: " << BruteResult(arr) << endl;
    cout << "DpResult: " << DpResult(arr) << endl;

    arr = {true, false, false};
    cout << "BruteResult: " << BruteResult(arr) << endl;
    cout << "DpResult: " << DpResult(arr) << endl;

    arr = {true, true, false, true};
    cout << "BruteResult: " << BruteResult(arr) << endl;
    cout << "DpResult: " << DpResult(arr) << endl;
    cout << "=================BooleanParenthesizationProblem====================" << endl;
  }

  int BruteResult(const vector<bool> &arr)
  {
    return BruteResultAux(arr, arr[0], 0);

  }

  int DpResult(const vector<bool> &arr)
  {
    return DpResultAux(arr);
  }

 private:
  int BruteResultAux(const vector<bool> &arr, bool value, int pos)
  {
    if (pos + 1 == static_cast<int>(arr.size()))
    {
      return value ? 1 : 0;
    }

    int sum1 = BruteResultAux(arr, (value | arr[pos+1]), pos + 1);
    int sum2 = BruteResultAux(arr, (value ^ arr[pos+1]), pos + 1);
    int sum3 = BruteResultAux(arr, (value & arr[pos+1]), pos + 1);

    return sum1 + sum2 + sum3;
  }

  int DpResultAux(const vector<bool> &arr)
  {
    return 0;
  }

  void showBookmark(vector<vector<int>> &bookmark)
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
