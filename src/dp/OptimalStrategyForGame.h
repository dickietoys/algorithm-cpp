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

    arr = {8, 15, 3, 7};
    cout << "BruteSelect(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << BruteSelect(arr) << endl;

    arr = {2, 2, 2, 2};
    cout << "BruteSelect(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << BruteSelect(arr) << endl;

    arr = {20, 30, 2, 2, 2, 10};
    cout << "BruteSelect(";
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(cout, ", "));
    cout << ") : " << BruteSelect(arr) << endl;
    cout << "=================OptimalStrategyForGame====================" << endl;
  }

  int BruteSelect(const vector<int> &arr)
  {
    return BruteSelectAux(arr, 0, arr.size() - 1, 0);
  }

  int DpHasSubset(const vector<int> &arr, int targetSum)
  {
    return 0;
  }

 private:
  int BruteSelectAux(const vector<int> &arr, int leftPos, int rightPos, int sum)
  {
    if (leftPos >= rightPos)
    {
      return sum;
    }

    if arr[leftPos+1] >= arr[rightPos-1]

    // 选择第一个,并且对手选择了最后一个
    int sum1 = BruteSelectAux(arr, leftPos + 1, rightPos - 1, sum + arr[leftPos]);
    // 选择第一个，并且对手也选择了第一个
    int sum2 = BruteSelectAux(arr, leftPos + 2, rightPos, sum + arr[leftPos]);
    // 选择最后一个,并且对手选择了最后一个
    int sum3 = BruteSelectAux(arr, leftPos, rightPos - 2, sum + arr[rightPos]);
    // 选择最后一个，并且对手也选择了第一个
    int sum4 = BruteSelectAux(arr, leftPos + 1, rightPos - 1, sum + arr[rightPos]);

    return std::min({sum1, sum2, sum3, sum4});
  }

  int DpHasSubsetAux(const vector<int> &arr, int sum)
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
