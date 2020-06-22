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
    // 4
    int result = coinChangeProblemRecur({1, 2, 3}, 4);
    cout << "coinChangeProblemRecur: " << result << endl;
    // 5
    result = coinChangeProblemRecur({2, 5, 3, 6}, 10);
    cout << "coinChangeProblemRecur: " << result << endl;

    cout << "==================dp======================" << endl;
    result = coinChangeProblemDp({1, 2, 3}, 4);
    cout << "coinChangeProblemDp: " << result << endl;
    result = coinChangeProblemDp({2, 5, 3, 6}, 10);
    cout << "coinChangeProblemDp: " << result << endl;
  }

  int coinChangeProblemRecurAux(vector<int> coins, int pos, int n)
  {
    if (n == 0)
    {
      return 1;
    }

    if (pos >= coins.size() || n < 0)
    {
      return 0;
    }

    return coinChangeProblemRecurAux(coins, pos, n - coins[pos]) +
        coinChangeProblemRecurAux(coins, pos + 1, n);
  }

  int coinChangeProblemRecur(vector<int> coins, int n)
  {
    int coins_size = coins.size();
    if (coins_size <= 0)
    {
      return 0;
    }

    return coinChangeProblemRecurAux(coins, 0, n);
  }

  int coinChangeProblemDp(vector<int> coins, int n)
  {
    int coins_size = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(coins_size, 0));
    for (int i = 0; i < coins_size; i++)
    {
      dp[0][i] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
      for (int j = 0; j < coins_size; ++j)
      {
        int v1 = j - 1 >= 0 ? dp[i][j-1] : 0;
        int v2 = i - coins[j] >= 0 ? dp[i-coins[j]][j] : 0;
        dp[i][j] = v1+v2;
      }
    }

    return dp[n][coins_size - 1];
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
