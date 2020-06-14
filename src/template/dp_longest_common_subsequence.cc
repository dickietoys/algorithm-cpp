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
    int result = LcsRecur("AGGTAB", "GXTXAYB");
    cout << "LcsRecur: " << result << endl;

    result = LcsDp("AGGTAB", "GXTXAYB");
    cout << "LcsDp: " << result << endl;
  }

  int LcsRecur(string s1, string s2)
  {
    return LcsDp(s1, s2);
  }

  int LcsDp(string s1, string s2)
  {
    int s1_size = s1.size();
    int s2_size = s2.size();
    if (s1.empty())
    {
      return s2_size;
    }

    if (s2.empty())
    {
      return s1_size;
    }

    vector<vector<int>> dp(s1_size, vector<int>(s2_size, 0));
    for (int i = 0; i < s2_size; ++i)
    {
      if (s1[0] == s2[i])
      {
        dp[0][i] = 1;
      }
      else if (i != 0)
      {
        dp[0][i] = dp[0][i-1];
      }
      else
      {
        dp[0][i] = 0;
      }
    }

    for (int i = 0; i < s1_size; ++i)
    {
      if (s1[i] == s2[0])
      {
        dp[i][0] = 1;
      }
      else if (i != 0)
      {
        dp[i][0] = dp[i-1][0];
      }
      else
      {
        dp[i][0] = 0;
      }
    }

    for (int i = 1; i < s1_size; ++i)
    {
      for (int j = 1; j < s2_size; ++j)
      {
        if (s1[i] == s2[j])
        {
          dp[i][j] = dp[i-1][j-1] + 1;
        }
        else
        {
          dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
      }
    }

    return dp[s1_size - 1][s2_size- 1];
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
