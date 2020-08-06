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
    int result = numSquares(12);
    cout << result << endl;
  }

  int Aux(int n)
  {
    if (n == 0)
    {
      return 0;
    }

    if (n < 0)
    {
      return -1;
    }

    int min = std::numeric_limits<int>::max();
    for (int i = 1; i * i <= n; ++i)
    {
      int cur = Aux(n - i*i);
      if (cur != -1)
      {
        min = std::min(cur + 1, min);
      }
    }

    if (min == std::numeric_limits<int>::max())
    {
      return -1;
    }
    else
    {
      return min;
    }
  }

  int numSquares(int n) {
    // return Aux(n);

    /*
      f(n) = f(n-1)
             f(n-4)
             f(n-9) ...
     */
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
      int min = std::numeric_limits<int>::max();
      for (int j = 1; j * j <= i; ++j)
      {
        int pos = i - j * j;
        if (pos == 0)
        {
          min = std::min(min, 1);
        }
        else
        {
          if (dp[pos] != 0)
          {
            min = std::min(dp[pos] + 1, min);
          }
        }
      }
      dp[i] = min == std::numeric_limits<int>::max() ? 0 : min;
    }

    return dp[n];
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
