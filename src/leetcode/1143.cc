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

  int longestCommonSubsequence(string text1, string text2) {
    /*
      dp[i][j] = 1. dp[i-1][j]
                 2. dp[i][j-1]
                 3. dp[i-1][j-1] + 1
    */
    vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
    if (text1[0] == text2[0])
    {
      dp[0][0] = 1;
    }

    for (int i = 1; i < text1.size(); ++i)
    {
      if (text1[i] == text2[0])
      {
        dp[i][0] = 1;
      }
      else
      {
        dp[i][0] = dp[i-1][0];
      }
    }

    for (int i = 1; i < text2.size(); ++i)
    {
      if (text2[i] == text1[0])
      {
        dp[0][i] = 1;
      }
      else
      {
        dp[0][i] = dp[0][i-1];
      }
    }

    for (int i = 1; i < text1.size(); ++i)
    {
      for (int j = 1; j < text2.size(); ++j)
      {
        if (text1[i] == text2[j])
        {
          dp[i][j] = dp[i-1][j-1] + 1;
        }
        else
        {
          dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
      }
    }

    return dp[text1.size() - 1][text2.size() -1];
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
