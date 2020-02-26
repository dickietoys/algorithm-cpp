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
#include <bitset>

using namespace std;

class Solution {
 public:

  void RunTest()
  {
    vector<int> input = {7, 1, 5, 3, 6, 4};
    int result = maxProfit(input);
    cout << "result: " << result << endl;
  }

  int maxProfit(vector<int>& prices)
  {
    if (prices.size() < 2)
    {
      return 0;
    }
    vector<int> profits(prices.size(), 0);
    for (int i = 1; i < prices.size(); ++i)
    {
      profits[i] = prices[i] - prices[i-1];
    }
    return Aux(profits, 0, prices.size() - 1);
  }

  int KadeneAlgo(vector<int>& prices)
  {
    if (prices.size() < 2)
    {
      return 0;
    }
    vector<int> profits(prices.size(), 0);
    for (int i = 1; i < prices.size(); ++i)
    {
      profits[i] = prices[i] - prices[i-1];
    }

    vector<int> dp(profits.size(), 0);
    dp[0] = profits[0];
    int max_sum = std::max(dp[0], 0);
    for (int i = 1; i < profits.size(); ++i)
    {
      dp[i] = std::max(dp[i-1], 0) + profits[i];
      max_sum = std::max(max_sum, dp[i]);
    }

    return max_sum;
  }

  int Aux(vector<int>& prices, int left, int right)
  {
    if (left >= right)
    {
      return prices[left];
    }

    int mid = (left + right) / 2;
    int left_sum = Aux(prices, left, mid);
    int right_sum = Aux(prices, mid + 1, right);
    int cross_sum = AuxCross(prices, left, mid, right);

    return std::max({left_sum, right_sum, cross_sum});
  }

  int AuxCross(vector<int>& prices, int left, int mid, int right)
  {
    if (left >= right)
    {
      return prices[left];
    }

    int left_sum = std::numeric_limits<int>::min();
    int sum = 0;
    for (int i = mid; i >= left; --i)
    {
      sum += prices[i];
      if (sum > left_sum)
      {
        left_sum = sum;
      }
    }

    int right_sum = std::numeric_limits<int>::min();
    sum = 0;
    for (int i = mid + 1; i <= right; ++i)
    {
      sum += prices[i];
      if (sum > right_sum)
      {
        right_sum = sum;
      }
    }

    return right_sum + left_sum;
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
    }
    cout << endl;
  }

  template<class T>
  void Show(vector<vector<T>> &result)
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
