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
#include <functional>
#include <list>
#include <exception>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  void RunTest()
  {
  }

  int maxProfit(vector<int>& prices) {
    /*
      i 是交易次数  j 价格
      dp[i][j] = 1. dp[i][j-1] 不做买卖，与前一天收益一样
      2. prices[j] - (prices[k] - dp[i-1][k-2])  [0 .. j - 1]
    */

    if (prices.empty())
    {
      return 0;
    }
    int max_transaction = prices.size() / 2;
    vector<vector<int>> dp(max_transaction + 1, vector<int>(prices.size(), 0));
    for (int i = 1; i <= max_transaction; ++i)
    {
      int min = std::numeric_limits<int>::max();
      for (int j = 1; j < prices.size(); ++j)
      {
        // int max_profit = 0;
        // for (int k = 0; k < j; ++k)
        // {
        //   int tmp = dp[i-1][k] + prices[j] - prices[k];
        //   max_profit = std::max(max_profit, tmp);
        // }
        // dp[i][j] = std::max(max_profit, dp[i][j-1]);
        if ((j-3 < 0))
        {
          min = std::min(min, prices[j-1]);
        }
        else
        {
          min = std::min(min, prices[j-1] - dp[i-1][j-3]);
        }
        dp[i][j] = std::max(dp[i][j-1], prices[j] - min);
      }
    }

    return dp.back().back();
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
  delete solution;
  return 0;
}
