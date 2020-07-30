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

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
 public:
  void RunTest()
  {
    vector<int> coins = {1, 2, 5};
    int result = coinChange(coins, 11);
    cout << result << endl;
  }

  int Aux(vector<int>& coins, int amount, vector<int> &dp)
  {
    if (amount < 0)
    {
      return -1;
    }

    if (amount == 0)
    {
      return 0;
    }

    if (dp[amount] != -2)
    {
      return dp[amount];
    }

    int min = std::numeric_limits<int>::max();
    for (int i = 0; i < coins.size(); ++i)
    {
      int val = Aux(coins, amount - coins[i], dp);
      if (val != -1)
      {
        min = std::min(min, val + 1);
      }
    }

    dp[amount] = min == std::numeric_limits<int>::max() ? -1 : min;
    return dp[amount];
  }

  int coinChange(vector<int>& coins, int amount) {
    // vector<int> dp(amount + 1, -2);
    // return Aux(coins, amount, dp);

    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i)
    {
      int cur_min = std::numeric_limits<int>::max();
      for (int j = 0; j < coins.size(); ++j)
      {
        int remain = i - coins[j];
        if (remain >= 0 && dp[remain] != -1)
        {
          cur_min = std::min(cur_min, dp[remain] + 1);
        }
      }
      if (cur_min == std::numeric_limits<int>::max())
      {
        cur_min = -1;
      }
      dp[i] = cur_min;
    }

    return dp[amount];
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", " << endl;
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
