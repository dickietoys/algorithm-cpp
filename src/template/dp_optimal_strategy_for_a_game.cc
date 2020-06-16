#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <iterator>
#include <set>
#include <cmath>
#include <queue>
#include <list>

using namespace std;


class Solution {
 public:
  void RunTest()
  {
    cout << "==================bruteforce======================" << endl;
    // 15
    int result = OptimalStrategyForAGameRecur({5, 3, 7, 10});
    cout << "OptimalStrategyForAGameRecur: " << result << endl;
    // 22
    result = OptimalStrategyForAGameRecur({8, 15, 3, 7});
    cout << "OptimalStrategyForAGameRecur: " << result << endl;
    // 4
    result = OptimalStrategyForAGameRecur({2, 2, 2, 2});
    cout << "OptimalStrategyForAGameRecur: " << result << endl;
    // 42
    result = OptimalStrategyForAGameRecur({20, 30, 2, 2, 2, 10});
    cout << "OptimalStrategyForAGameRecur: " << result << endl;

    cout << "==================dp======================" << endl;
    result = OptimalStrategyForAGameDp({5, 3, 7, 10});
    cout << "OptimalStrategyForAGameDp: " << result << endl;
    result = OptimalStrategyForAGameDp({8, 15, 3, 7});
    cout << "OptimalStrategyForAGameDp: " << result << endl;
    result = OptimalStrategyForAGameDp({2, 2, 2, 2});
    cout << "OptimalStrategyForAGameDp: " << result << endl;
    result = OptimalStrategyForAGameDp({20, 30, 2, 2, 2, 10});
    cout << "OptimalStrategyForAGameDp: " << result << endl;
  }

  int OptimalStrategyForAGameRecurAux(vector<int> arr, int lpos, int rpos, int sum)
  {
    if (lpos > rpos)
    {
      return sum;
    }

    int value1 = std::min(
        OptimalStrategyForAGameRecurAux(arr, lpos + 1 + 1, rpos, sum + arr[lpos]),
        OptimalStrategyForAGameRecurAux(arr, lpos + 1, rpos - 1, sum + arr[lpos]));
    int value2 = std::min(
        OptimalStrategyForAGameRecurAux(arr, lpos + 1, rpos - 1, sum + arr[rpos]),
        OptimalStrategyForAGameRecurAux(arr, lpos, rpos - 1 -1, sum + arr[rpos]));


    return std::max(value1, value2);
  }

  int OptimalStrategyForAGameRecur(vector<int> arr)
  {
    int arr_size = arr.size();
    if (arr_size <= 0)
    {
      return 0;
    }

    return OptimalStrategyForAGameRecurAux(arr, 0, arr.size() - 1, 0);
  }

  int OptimalStrategyForAGameDp(vector<int> arr)
  {
    int arr_size = arr.size();
    if (arr_size <= 0)
    {
      return 0;
    }

    vector<vector<int>> dp(arr_size, vector<int>(arr_size, 0));
    for (int i = 0; i < arr_size; ++i)
    {
      for (int j = 0, k = i; k < arr_size; ++j, ++k)
      {
        int val1 = (j+2 <= k) ? dp[j+2][k] : 0;
        int val2 = (j+1 < k-1) ? dp[j+1][k-1] : 0;
        int val3 = (j <= k - 2) ? dp[j][k-2] : 0;
        dp[j][k] = std::max(
            std::min(arr[j] + val1, arr[j] + val2),
            std::min(arr[k] + val2, arr[k] + val3));
      }
    }

    return dp[0][arr_size-1];
  }

  template<class T>
  void Show(const vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
    }
    cout << endl;
  }

  template<class T>
  void Show(const vector<vector<T>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ", ";
      }
      cout << endl;
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
