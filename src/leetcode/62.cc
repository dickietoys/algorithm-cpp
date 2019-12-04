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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    int input;
    int result;

    result = uniquePaths(3, 2);
    cout << "result: " << result << endl;
    assert(result == 3);

    result = uniquePaths(7, 3);
    cout << "result: " << result << endl;
    assert(result == 28);
  }

  int uniquePaths(int m, int n) {
    // return Aux(m, n, 1, 1);
    return DpAux(m, n);
  }

  int DpAux(int m, int n)
  {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i)
    {
      dp[1][i] = 1;
    }

    for (int i = 2; i <= m; ++i)
    {
      dp[i][1] = 1;
    }

    for (int i = 2; i <= m; ++i)
    {
      for (int j = 2; j <= n; ++j)
      {
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }

    return dp[m][n];
  }

  int Aux(int m, int n, int xpos, int ypos)
  {
    if (m == ypos && n == xpos)
    {
      return 1;
    }

    if (m < ypos || n < xpos)
    {
      return 0;
    }

    return Aux(m, n, xpos + 1, ypos) + Aux(m, n, xpos, ypos + 1);
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
