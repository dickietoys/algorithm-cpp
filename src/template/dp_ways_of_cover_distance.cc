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
    int result = WaysToCoverDistanceRecur(3);
    cout << "WaysToCoverDistanceRecur: " << result << endl;
    result = WaysToCoverDistanceRecur(4);
    cout << "WaysToCoverDistanceRecur: " << result << endl;

    cout << "==================dp======================" << endl;
    result = WaysToCoverDistanceDp(3);
    cout << "WaysToCoverDistanceDp: " << result << endl;
    result = WaysToCoverDistanceDp(4);
    cout << "WaysToCoverDistanceDp: " << result << endl;
  }

  int WaysToCoverDistanceRecurAux(int n)
  {
    if (n == 0)
    {
      return 1;
    }

    if (n < 0)
    {
      return 0;
    }

    return WaysToCoverDistanceRecurAux(n - 1) + WaysToCoverDistanceRecurAux(n - 2) + WaysToCoverDistanceRecurAux(n - 3);
  }

  int WaysToCoverDistanceRecur(int n)
  {
    return WaysToCoverDistanceRecurAux(n);
  }

  int WaysToCoverDistanceDp(int n)
  {
    if (n == 0)
    {
      return 0;
    }

    int dp_size = n < 3 ? 3 : n;

    vector<int> dp(dp_size + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n; ++i)
    {
      dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }

    return dp[n];
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
