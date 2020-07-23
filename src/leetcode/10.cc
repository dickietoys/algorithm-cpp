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
    return Aux(s, p, s.size() - 1, p.size() - 1);
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
