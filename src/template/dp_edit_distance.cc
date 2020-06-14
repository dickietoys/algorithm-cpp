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
    cout << "==================bruteforce======================" << endl;
    int result = EditDistanceRecur("geek", "gesek");
    cout << "EditDistanceRecur: " << result << endl;
    result = EditDistanceRecur("cat", "cut");
    cout << "EditDistanceRecur: " << result << endl;
    result = EditDistanceRecur("sunday", "saturday");
    cout << "EditDistanceRecur: " << result << endl;

    cout << "==================dp======================" << endl;
    result = EditDistanceDp("geek", "gesek");
    cout << "EditDistanceDp: " << result << endl;
    result = EditDistanceDp("cat", "cut");
    cout << "EditDistanceDp: " << result << endl;
    result = EditDistanceDp("sunday", "saturday");
    cout << "EditDistanceDp: " << result << endl;
  }


  int EditDistanceRecurAux(string s1, int s1pos, string s2, int s2pos)
  {
    int s1_size = s1.size();
    int s2_size = s2.size();
    if (s1pos >= s1_size)
    {
      return s2_size - s2pos;
    }

    if (s2pos >= s2_size)
    {
      return s1_size - s1pos;
    }

    int min = 0;

    if (s1[s1pos] == s2[s2pos])
    {
      min = EditDistanceRecurAux(s1, s1pos + 1, s2, s2pos + 1);
    }
    else
    {
      min = std::min({EditDistanceRecurAux(s1, s1pos + 1, s2, s2pos + 1),
            EditDistanceRecurAux(s1, s1pos + 1, s2, s2pos),
            EditDistanceRecurAux(s1, s1pos, s2, s2pos + 1)}) + 1;
    }

    return min;
  }

  int EditDistanceRecur(string s1, string s2)
  {
    return EditDistanceRecurAux(s1, 0, s2, 0);
  }

  int EditDistanceDp(string s1, string s2)
  {
    int s1_size = s1.size();
    int s2_size = s2.size();
    if (s1_size == 0)
    {
      return s2_size;
    }

    if (s2_size == 0)
    {
      return s1_size;
    }

    vector<vector<int>> dp(s1_size, vector<int>(s2_size, 0));
    for (int i = 0; i < s2_size; ++i)
    {
      if (s1[0] == s2[i])
      {
        dp[0][i] = i;
      }
      else if (i != 0)
      {
        dp[0][i] =  dp[0][i-1] + 1;
      }
      else
      {
        dp[0][i] = 1;
      }
    }

    for (int i = 0; i < s1_size; ++i)
    {
      if (s1[i] == s2[0])
      {
        dp[i][0] = i;
      }
      else if (i != 0)
      {
        dp[i][0] =  dp[i-1][0] + 1;
      }
      else
      {
        dp[i][0] = 1;
      }
    }

    for (int i = 1; i < s1_size; ++i)
    {
      for (int j = 1; j < s2_size; ++j)
      {
        if (s1[i] == s2[j])
        {
          dp[i][j] = dp[i-1][j-1];
        }
        else
        {
          dp[i][j] = std::min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
        }
      }
    }

    return dp[s1_size - 1][s2_size - 1];
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
