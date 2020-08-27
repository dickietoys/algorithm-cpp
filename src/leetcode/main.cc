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

// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//         left = NULL;
//         right = NULL;
//     }

//     Node(int _val, Node* _left, Node* _right) {
//         val = _val;
//         left = _left;
//         right = _right;
//     }
// };

class Solution {
 public:
  void RunTest()
  {

  }

  int Aux(int start_pos, int stop_pos, vector<vector<int>> &dp)
  {
    if (start_pos >= stop_pos)
    {
      return 1;
    }

    if (dp[start_pos][stop_pos] != -1)
    {
      return dp[start_pos][stop_pos];
    }

    int count = 0;
    for (int i = start_pos; i <= stop_pos; ++i)
    {
      int all_left = Aux(start_pos, i - 1, dp);
      int all_right = Aux(i + 1, stop_pos, dp);
      count += all_left * all_right;
    }

    dp[start_pos][stop_pos] = count;

    return count;
  }

  int numTrees(int n) {
    if (n == 0)
    {
      return 0;
    }

    // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    // return Aux(1, n, dp);

    /*
      f(n, m) = 1. f(n, n) * f(n+2, m)
                2. f(n, n+1) * f(n+3, m)
                3. f(n, n+2) * f(n+4, m)
     */

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    for (int i = 1; i <= n; ++i)
    {
      dp[i][i] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
      for (int j = i; j <= n; ++j)
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
