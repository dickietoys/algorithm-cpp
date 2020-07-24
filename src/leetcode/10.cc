#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    string s = "";
    string p = "";
    bool result = false;

    s = "aa";
    p = "a";
    result = isMatch(s, p);
    cout << "result: " << result << endl;
    assert(result = false);

    s = "aa";
    p = "a*";
    result = isMatch(s, p);
    cout << "result: " << result << endl;
    assert(result = true);

    s = "ab";
    p = ".*";
    result = isMatch(s, p);
    cout << "result: " << result << endl;
    assert(result = true);

    s = "aab";
    p = "c*a*b";
    result = isMatch(s, p);
    cout << "result: " << result << endl;
    assert(result = true);

    s = "mississippi";
    p = "mis*is*p*.";
    result = isMatch(s, p);
    cout << "result: " << result << endl;
    assert(result = false);
  }

  bool Aux(string &s, string &p, int s_pos, int p_pos)
  {
    if (p_pos < 0)
    {
      return s_pos < 0;
    }

    if (p[p_pos] == '*')
    {
      if (s_pos >= 0 && (p[p_pos - 1] == '.' || p[p_pos - 1] == s[s_pos]))
      {
        return Aux(s, p, s_pos, p_pos - 2) || Aux(s, p, s_pos - 1, p_pos);
      }
      else
      {
        return Aux(s, p, s_pos, p_pos - 2);
      }
    }
    else
    {
      if (s_pos >= 0 && (p[p_pos] == '.' || p[p_pos] == s[s_pos]))
      {
        return Aux(s, p, s_pos - 1, p_pos - 1);
      }
      else
      {
        return false;
      }
    }
  }

  bool isMatch(string s, string p)
  {
    // return Aux(s, p, s.size() - 1, p.size() - 1);
    // f(n,m) = f(n, m-2) || f(n-1, m) || f(n-1, m-1);

    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= s.size(); ++i)
    {
      for (int j = 1; j <= p.size(); ++j)
      {
        if (p[j-1] == '*')
        {
          if (i > 0 && (p[j-2] == '.' || p[j - 2] == s[i - 1]))
          {
            dp[i][j] = dp[i][j-2] || dp[i-1][j];
          }
          else
          {
            dp[i][j] = dp[i][j-2];
          }
        }
        else
        {
          if (i > 0 && (p[j-1] == '.' || p[j-1] == s[i-1]))
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
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
