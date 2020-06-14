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
    int result = LpsRecur("forgeeksskeegfor");
    cout << "LpsRecur: " << result << endl;

    result = LpsDp("forgeeksskeegfor");
    cout << "LpsDp: " << result << endl;
  }

  int LpsRecur(string s)
  {
    int s_size = s.size();
    if (s.empty())
    {
      return 0;
    }

    int max = 0;
    for (int i = 1; i <= s_size; ++i)
    {
      for (int j = 0; j < s_size - i + 1; ++j)
      {
        int k = j + i - 1;
        int lpos = j;
        int rpos = k;
        bool is_palindrome = true;
        while (lpos <= rpos)
        {
          if (s[lpos] != s[rpos])
          {
            is_palindrome = false;
            break;
          }
          ++lpos;
          --rpos;
        }

        if (is_palindrome)
        {
          max = std::max(max, k - j + 1);
        }
      }
    }

    return max;
  }

  int LpsDp(string s)
  {
    int s_size = s.size();
    if (s.empty())
    {
      return 0;
    }

    int max = 1;
    vector<vector<bool>> dp(s_size, vector<bool>(s_size, false));
    for (int i = 0; i < s_size; ++i)
    {
      dp[i][i] = true;
    }

    for (int i = 1; i < s_size; ++i)
    {
      if (s[i-1] == s[i])
      {
        dp[i-1][i] = true;
        max = 2;
      }
    }

    for (int i = 3; i <= s_size; ++i)
    {
      for (int j = 0; j < s_size - i + 1; ++j)
      {
        int k = j + i - 1;
        if (dp[j+1][k-1] && s[j] == s[k])
        {
          max = std::max(i, max);
          dp[j][k] = true;
        }
      }
    }

    return max;
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
