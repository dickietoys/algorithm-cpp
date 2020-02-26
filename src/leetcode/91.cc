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
#include <bitset>

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    string input;
    int result;

    input = "12";
    result = numDecodings(input);
    cout << "result: " << result << endl;
    assert(result == 2);

    input = "226";
    result = numDecodings(input);
    cout << "result: " << result << endl;
    assert(result == 3);
  }

  int numDecodings(string s) {
    // return Aux(s, 0);
    return DpAux(s);
  }

  int DpAux(string &s)
  {
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    if (s[0] != '0')
    {
      dp[1] = 1;
    }
    else
    {
      return 0;
    }

    for (int i = 2; i <= s.size(); ++i)
    {
      int first = stoi(s.substr(i-1, 1));
      int second = stoi(s.substr(i-2, 2));
      if (first != 0)
      {
        dp[i] += dp[i-1];
      }

      if (second >= 10 && second <= 26)
      {
        dp[i] += dp[i-2];
      }
    }

    return dp[s.size()];
  }

  int Aux(string &s, int pos)
  {
    int sSize = s.size();
    if (pos >= sSize)
    {
      return 1;
    }

    int n1 = 0;
    int n2 = 0;
    if (s[pos] != '0')
    {
      n1 = Aux(s, pos + 1);
    }
    else
    {
      return 0;
    }

    if (pos + 2 <= sSize && stoi(s.substr(pos, 2)) <= 26)
    {
      n2 = Aux(s, pos + 2);
    }

    return n1+n2;
  }

  void Show(vector<int> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
  }

  void Show(vector<vector<int>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ",";
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
