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
    int result = minCut("aab");
    cout << result << endl;
  }

  int Aux(string &s, vector<vector<bool>> &dp_palindrome, int start_pos, vector<int> &dp)
  {
    if (start_pos > s.size() -1 || dp_palindrome[start_pos][s.size() - 1])
    {
      return 0;
    }

    if (dp[start_pos] != -1)
    {
      return dp[start_pos];
    }

    int cur_min = std::numeric_limits<int>::max();
    for (int i = start_pos; i < s.size() ; ++i)
    {
      int s1_left = start_pos;
      int s1_right = i;
      int s2_left = i + 1;
      int s2_right = s.size() - 1;

      if (dp_palindrome[s1_left][s1_right])
      {
        cur_min = std::min(cur_min, Aux(s, dp_palindrome, i + 1, dp) + 1);
      }
    }

    dp[start_pos] = cur_min;
    return cur_min;
  }

  int minCut(string s) {
    vector<vector<bool>> dp_palindrome(s.size(), vector<bool>(s.size(), false));
    dp_palindrome[0][0] = true;
    for (int i = 1; i < s.size(); ++i)
    {
      dp_palindrome[i][i] = true;
      if (s[i-1] == s[i])
      {
        dp_palindrome[i-1][i] = true;
      }
    }

    for (int i = 3; i <= s.size(); ++i)
    {
      for (int j = 0; j + i - 1 < s.size(); ++j)
      {
        int left = j;
        int right = j + i - 1;
        if (s[left] == s[right] && dp_palindrome[left+1][right-1])
        {
          dp_palindrome[left][right] = true;
        }
      }
    }

    // vector<int> dp(s.size(), -1);
    // return Aux(s, dp_palindrome, 0, dp);

    vector<int> dp(s.size(), 0);
    for (int i = 0; i < s.size(); ++i)
    {
      if (dp_palindrome[0][i])
      {
        dp[i] = 0;
      }
      else
      {
        int cur_min = std::numeric_limits<int>::max();
        for (int j = 0; j < i; ++j)
        {
          int left = i - j;
          int right = i;
          if (dp_palindrome[left][right])
          {
            cur_min = std::min(cur_min, dp[left - 1] + 1);
          }
        }
        dp[i] = cur_min;
      }
    }

    return dp[s.size() - 1];
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
