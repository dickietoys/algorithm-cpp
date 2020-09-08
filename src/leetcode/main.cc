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

  /*
    You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

    Example 1:
    Input: coins = [1, 2, 5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1

    Example 2:
    Input: coins = [2], amount = 3
    Output: -1
  */
  int Aux(vector<int>& coins, int coins_pos, int amount)
  {
    if (amount == 0)
    {
      return 0;
    }

    if (coins_pos >= coins.size())
    {
      return -1;
    }

    int min_size = std::numeric_limits<int>::max();
    if (amount - coins[coins_pos] >= 0)
    {
      min_size = Aux(coins, coins_pos, amount - coins[coins_pos]);
      if (min_size == -1)
      {
        min_size = std::numeric_limits<int>::max();
      }
      else
      {
        min_size += 1;
      }
    }

    int tmp = Aux(coins, coins_pos + 1, amount) == -1;
  }

  int coinChange(vector<int>& coins, int amount) {
    /*
      i: coins size
      j: amount
      dp[i][j] = 1. dp[i-1][j]
                 2. dp[i][j+coins[i]]

     */
    vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));

    for (int i = 0; i < coins.size(); ++i)
    {
      for (int j = 0; j <= amount; ++j)
      {

      }
    }
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
