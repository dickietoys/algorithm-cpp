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
    int result = numDistinct("rabbbit", "rabbit");
    cout << "result: " << result << endl;
  }

  int Aux(string s, string t, int s_pos, int t_pos)
  {
    if (t_pos >= t.size())
    {
      return 1;
    }

    if (s_pos >= s.size())
    {
      return 0;
    }

    int sum = 0;
    if (s[s_pos] == t[t_pos])
    {
      sum += Aux(s, t, s_pos + 1, t_pos + 1);
    }
    sum += Aux(s, t, s_pos + 1, t_pos);

    return sum;
  }

  int numDistinct(string s, string t) {
    // return Aux(s, t, 0, 0);

    /*
      [n, s.size()]  [m, t.size()]
      f(n, m) = 1. f(n + 1, m + 1) + f(n+1, m)  s[n] == t[m]
                2. f(n+1, m);                   s[n] != t[m]

      f(n, m) = f(n-1, m-1) || f(n-1, m) [0, n]  [0, m]
    */
    vector<vector<long>> dp(t.size() + 1, vector<long>(s.size() + 1, 0));
    for (int i = 0; i <= s.size(); ++i)
    {
      dp[0][i] = 1;
    }

    for (int i = 1; i <= t.size(); ++i)
    {
      for (int j = 1; j <= s.size(); ++j)
      {
        dp[i][j] = dp[i][j-1];
        if (t[i-1] == s[j-1])
        {
          dp[i][j] += dp[i-1][j-1];
        }
      }
    }

    return dp[t.size()][s.size()];
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
