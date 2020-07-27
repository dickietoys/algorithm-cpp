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
    vector<vector<int>> triangle = {
      {2},
      {3,4},
      {6,5,7},
      {4,1,8,3}
    };
    int result = minimumTotal(triangle);
    cout << "result: " << result << endl;
  }

  int Aux(vector<vector<int>>& triangle, int row_pos, int col_pos)
  {
    if (row_pos >= triangle.size())
    {
      return 0;
    }

    int size1 = Aux(triangle, row_pos + 1, col_pos);
    int size2 = size2 = Aux(triangle, row_pos + 1, col_pos + 1);

    return std::min(size1, size2) + triangle[row_pos][col_pos];
  }

  int minimumTotal(vector<vector<int>>& triangle) {
    // return Aux(triangle, 0, 0);

    /*
      f(n,m) = min(f(n+1, m), f(n+1, m+1)) + arr[n][m]

      f(n,m)
     */

    vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), 0));
    for (int i = 0; i < triangle[triangle.size()-1].size(); ++i)
    {
      dp[triangle.size()-1][i] = triangle[triangle.size()-1][i];
    }

    for (int i = triangle.size() - 2; i >= 0; --i)
    {
      for (int j = triangle[i].size() - 1; j >= 0; --j)
      {
        dp[i][j] = std::min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
      }
    }

    return dp[0][0];
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
