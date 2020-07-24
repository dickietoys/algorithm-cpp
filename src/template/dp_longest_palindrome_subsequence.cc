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
#include <list>

using namespace std;


class Solution {
 public:
  void RunTest()
  {
    int result = LpsRecur("GEEKSFORGEEKS");
    cout << "LpsRecur: " << result << endl;

    result = LpsDp("GEEKSFORGEEKS");
    cout << "LpsDp: " << result << endl;
  }

  int LpsRecurAux(string &s, int lpos, int rpos)
  {
    if (lpos == rpos)
    {
      return 1;
    }

    if (s[lpos] == s[rpos] && lpos + 1 == rpos)
    {
      return 2;
    }

    if (s[lpos] == s[rpos])
    {
      return LpsRecurAux(s, lpos + 1, rpos - 1) + 2;
    }
    else
    {
      return std::max(LpsRecurAux(s, lpos + 1, rpos), LpsRecurAux(s, lpos, rpos - 1));
    }
  }

  // f(n, m) = f(m+1, n-1) +2 || f(m+1, n), f(m, n-1)

  int LpsRecur(string s)
  {
    return LpsRecurAux(s, 0, s.size() - 1);
  }

  int LpsDp(string s)
  {
    int s_size = s.size();
    if (s.empty())
    {
      return 0;
    }

    vector<vector<int>> dp(s_size, vector<int>(s_size, 0));
    for (int i = 0; i < s_size; ++i)
    {
      dp[i][i] = 1;
    }

    for (int i = 2; i <= s_size; ++i)
    {
      for (int j = 0; j <= s_size - i; ++j)
      {
        int k = j + i - 1;
        if (s[j] == s[k])
        {
          if (j + 1 == k)
          {
            dp[j][k] = 2;
          }
          else
          {
            dp[j][k] = dp[j+1][k-1] + 2;
          }
        }
        else
        {
          dp[j][k] = std::max(dp[j+1][k], dp[j][k-1]);
        }
      }
    }

    return dp[0][s_size - 1];
  }


  template<class T>
  void Show(const vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
    }
    cout << endl;
  }

  template<class T>
  void Show(const vector<vector<T>> &result)
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

  return 0;
}
