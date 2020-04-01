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
  }

  //只允许一次交易
  int maxProfitWithOneTransaction(vector<int>& prices) {
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
  int maxProfitWithUnlimitedTransaction(vector<int>& prices) {
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
  int maxProfitWithMostTwiceTransaction(vector<int>& prices) {
    int prices_size = prices.size();
    vector<vector<int>> dp(prices_size, vector<int>(prices_size, 0));
    for (int i = 0;)
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
