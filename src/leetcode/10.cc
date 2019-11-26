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

  bool isMatch(string s, string p) {
    return Recursive(s, 0, p, 0);
  }

  bool Recursive(string s, int sPos, string p, int pPos)
  {
    if (sPos == s.size() && pPos == p.size())
    {
      return true;
    }

    if (sPos >= s.size() || pPos >= p.size())
    {
      return false;
    }

    bool result = false;
    if (Compare(s[sPos], p[pPos]))
    {
      result = Recursive(s, sPos + 1, p, pPos + 1);
    }

    result |= Recursive(s, sPos + 1, p, 0);

    return result;
  }

  bool Compare(char c, char p)
  {
    if (p == '.' || c == p)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
