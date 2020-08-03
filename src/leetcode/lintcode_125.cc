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
    int package_size = 10;
    vector<int> weights = {2,3,5,7};
    vector<int> values = {1,5,2,4};

    int result = backPackII(package_size, weights, values);
    cout << result << endl;
  }

  int Aux(int package_size,
          vector<int> &weights,
          vector<int> &values,
          int pos,
          vector<vector<int>> &dp)
  {
    if (pos >= weights.size())
    {
      return 0;
    }

    if (dp[pos][package_size] != -1)
    {
      return dp[pos][package_size];
    }

    int val1 = 0;
    int val2 = 0;
    if (package_size - weights[pos] >= 0)
    {
      val1 = values[pos] + Aux(package_size - weights[pos], weights, values, pos + 1, dp);
    }
    val2 = Aux(package_size, weights, values, pos + 1, dp);

    dp[pos][package_size] = std::max(val1, val2);
    return dp[pos][package_size];
  }

  int backPackII(int package_size, vector<int> &weights, vector<int> &values) {
    // vector<vector<int>> dp(weights.size(), vector<int>(package_size + 1, -1));
    // return Aux(package_size, weights, values, 0, dp);

    vector<vector<int>> dp(weights.size(), vector<int>(package_size + 1, 0));
    if (weights[0] <= package_size)
    {
      dp[0][weights[0]] = values[0];
    }

    for (int i = 1; i < weights.size(); ++i)
    {
      for (int j = 1; j <= package_size; ++j)
      {
        int last = j - weights[i];
        if (last == 0 || (last > 0 && dp[i-1][last] != 0))
        {
          dp[i][j] = std::max(dp[i-1][last] + values[i], dp[i-1][j]);
        }
        else
        {
          dp[i][j] = dp[i-1][j];
        }
      }
    }

    return *std::max_element(dp.rbegin()->begin(), dp.rbegin()->end());
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
