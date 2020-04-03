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

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  void RunTest()
  {
    vector<int> input = {3,3,5,0,0,3,1,4};
    int result = maxProfitWithMostTwiceTransaction(input);
    cout << "result: " << result << endl;
  }

  //只允许一次交易
  int maxProfitWithOneTransaction(vector<int>& prices)
  {
    int prices_size = prices.size();
    int max_value = 0;
    int cur_value = 0;
    for (int i = 1; i < prices_size; ++i)
    {
      cur_value = std::max(cur_value + prices[i] - prices[i-1], 0);
      max_value = std::max(cur_value, max_value);
    }

    return max_value;
  }

  //交易次数不限
  int maxProfitWithUnlimitedTransaction(vector<int>& prices)
  {
    int prices_size = prices.size();
    int max_value = 0;
    for (int i = 1; i < prices_size; ++i)
    {
      if (prices[i] > prices[i-1])
      {
        max_value += prices[i] - prices[i-1];
      }
    }

    return max_value;
  }

  //最多完成两笔交易
  int maxProfitWithMostTwiceTransaction(vector<int>& prices)
  {
    // dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1]
    int prices_size = prices.size();
    if (prices_size <= 1)
    {
      return 0;
    }

    int max_transaction = 2;
    vector<vector<int>> dp(max_transaction + 1, vector<int>(prices_size, 0));
    for (int k = 1; k <= max_transaction; ++k)
    {
      int min = prices[0];
      for (int i = 1; i < prices_size; ++i)
      {
        min = std::min(min,  prices[i] - dp[k-1][i-1]);
        dp[k][i] = std::max(dp[k][i-1], prices[i] - min);
      }
    }

    return dp[max_transaction][prices_size-1];
  }

  //最多完成k笔交易
  int maxProfitWithMostKthTransaction(int m, vector<int>& prices) {
    // dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1]
    int prices_size = prices.size();
    if (prices_size <= 1)
    {
      return 0;
    }

    if (m >= prices_size / 2)
    {
      int max_value = 0;
      for (int i = 1; i < prices_size; ++i)
      {
        if (prices[i] > prices[i-1])
        {
          max_value += prices[i] - prices[i-1];
        }
      }
      return max_value;
    }

    int max_transaction = m;
    vector<vector<int>> dp(max_transaction + 1, vector<int>(prices_size, 0));
    for (int k = 1; k <= max_transaction; ++k)
    {
      int min = prices[0];
      for (int i = 1; i < prices_size; ++i)
      {
        min = std::min(min,  prices[i] - dp[k-1][i-1]);
        dp[k][i] = std::max(dp[k][i-1], prices[i] - min);
      }
    }

    return dp[max_transaction][prices_size-1];
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
