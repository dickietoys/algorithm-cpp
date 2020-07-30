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
  }

  int Aux(int package_size,
           vector<int> &goods,
           int goods_pos,
           vector<vector<int>> &dp)
  {
    if (goods_pos >= goods.size())
    {
      return 0;
    }

    if (dp[goods_pos][package_size] != -1)
    {
      return dp[goods_pos][package_size];
    }

    int size1 = 0;
    int size2 = 0;
    if (package_size - goods[goods_pos] >= 0)
    {
      size1 = goods[goods_pos] + Aux(package_size - goods[goods_pos], goods, goods_pos + 1, dp);
    }
    size2 = Aux(package_size, goods, goods_pos + 1, dp);

    dp[goods_pos][package_size] = std::max(size1, size2);

    return dp[goods_pos][package_size];
  }

  int backPack(int package_size, vector<int> &goods) {
    // vector<vector<int>> dp(goods.size(), vector<int>(package_size + 1, -1));
    // return Aux(package_size, goods, 0, dp);

    /*
      f(n, m) = 1. f(n-1, m - arr[i]);
                2. f(n-1, m);
     */

    vector<vector<bool>> dp(goods.size(), vector<bool>(package_size + 1, false));
    for (int i = 0; i < goods.size(); ++i)
    {
      dp[i][0] = true;
    }

    if (goods[0] <= package_size)
    {
      dp[0][goods[0]] = true;
    }

    for (int i = 1; i < goods.size(); ++i)
    {
      for (int j = 1; j <= package_size; ++j)
      {
        if (j - goods[i] >= 0 && dp[i-1][j - goods[i]])
        {
          dp[i][j] = true;
        }
        else
        {
          dp[i][j] = dp[i-1][j];
        }
      }
    }

    const vector<bool> &last_row = *dp.rbegin();
    for (int i = last_row.size() - 1; i >= 0; --i)
    {
      if (last_row[i])
      {
        return i;
      }
    }

    return 0;
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
