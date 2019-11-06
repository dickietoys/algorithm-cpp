#ifndef OPTIMAL_STRATEGY_FOR_GAME_H_
#define OPTIMAL_STRATEGY_FOR_GAME_H_

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
*/
class OptimalStrategyForGame : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================OptimalStrategyForGame====================" << endl;
    vector<int> arr = {5, 3, 7, 10};
    cout << "BruteSelect(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << BruteSelect(arr) << endl;
    cout << "DpSelect(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << DpSelect(arr) << endl;

    arr = {8, 15, 3, 7};
    cout << "BruteSelect(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << BruteSelect(arr) << endl;
    cout << "DpSelect(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << DpSelect(arr) << endl;

    arr = {2, 2, 2, 2};
    cout << "BruteSelect(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << BruteSelect(arr) << endl;
    cout << "DpSelect(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << DpSelect(arr) << endl;

    arr = {20, 30, 2, 2, 2, 10};
    cout << "BruteSelect(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << BruteSelect(arr) << endl;
    cout << "DpSelect(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << DpSelect(arr) << endl;
    cout << "=================OptimalStrategyForGame====================" << endl;
  }

  int BruteSelect(const vector<int> &arr)
  {
    return BruteSelectAux(arr, 0, arr.size() - 1);
  }

  int DpSelect(const vector<int> &arr)
  {
    return DpSelectAux(arr);
  }

 private:
  int BruteSelectAux(const vector<int> &arr, int leftPos, int rightPos)
  {
    if (leftPos >= rightPos)
    {
      return 0;
    }

    int sum1 = arr[leftPos] + std::min(BruteSelectAux(arr, leftPos + 2, rightPos), BruteSelectAux(arr, leftPos + 1, rightPos - 1));
    int sum2 = arr[rightPos] + std::min(BruteSelectAux(arr, leftPos + 1, rightPos - 1), BruteSelectAux(arr, leftPos, rightPos - 2));

    return std::max(sum1, sum2);
  }

  int DpSelectAux(const vector<int> &arr)
  {
    vector<vector<int>> bookmark(arr.size(), vector<int>(arr.size(), 0));
    int arrLength = arr.size();
    for (int i = 0; i < arrLength; ++i)
    {
    }
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
