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
    bool result = isMatch("aa", "*");
    cout << result << endl;
  }

  bool Aux(string &s, string &p, int s_pos, int p_pos)
  {
    if (p_pos < 0)
    {
      return s_pos < 0;
    }

    if (p[p_pos] == '*')
    {
      if (s_pos >= 0)
      {
        return Aux(s, p, s_pos - 1, p_pos) || Aux(s, p, s_pos, p_pos - 1);
      }
      else
      {
        return Aux(s, p, s_pos, p_pos - 1);
      }
    }
    else
    {
      if (s_pos >= 0 && (p[p_pos] == '?' || s[s_pos] == p[p_pos]))
      {
        return Aux(s, p, s_pos - 1, p_pos - 1);
      }
      else
      {
        return false;
      }
    }
  }

  bool isMatch(string s, string p) {
    // return Aux(s, p, s.size() - 1, p.size() - 1);
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= s.size(); ++i)
    {
      for (int j = 1; j <= p.size(); ++j)
      {
        if (p[j-1] == '*')
        {
          if (i > 0)
          {
            dp[i][j] = dp[i-1][j] || dp[i][j-1];
          }
          else
          {
            dp[i][j] = dp[i][j-1];
          }
        }
        else
        {
          if (i > 0 && (p[j-1] == '?' || p[j-1] == s[i-1]))
          {
            dp[i][j] = dp[i-1][j-1];
          }
          else
          {
            dp[i][j] = false;
          }
        }
      }
    }

    return dp[s.size()][p.size()];
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
