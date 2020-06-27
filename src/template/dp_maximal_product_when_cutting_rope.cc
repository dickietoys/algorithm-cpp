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

    // 1
    int result = MaximalProductWhenCuttingRopeRecur(2);
    cout << "MaximalProductWhenCuttingRopeRecur: " << result << endl;

    // 2
    result = MaximalProductWhenCuttingRopeRecur(3);
    cout << "MaximalProductWhenCuttingRopeRecur: " << result << endl;

    // 4
    result = MaximalProductWhenCuttingRopeRecur(4);
    cout << "MaximalProductWhenCuttingRopeRecur: " << result << endl;

    // 6
    result = MaximalProductWhenCuttingRopeRecur(5);
    cout << "MaximalProductWhenCuttingRopeRecur: " << result << endl;

    // 10
    result = MaximalProductWhenCuttingRopeRecur(10);
    cout << "MaximalProductWhenCuttingRopeRecur: " << result << endl;

    cout << "==================dp======================" << endl;

    result = MaximalProductWhenCuttingRopeDp(2);
    cout << "MaximalProductWhenCuttingRopeDp: " << result << endl;

    result = MaximalProductWhenCuttingRopeDp(3);
    cout << "MaximalProductWhenCuttingRopeDp: " << result << endl;

    result = MaximalProductWhenCuttingRopeDp(4);
    cout << "MaximalProductWhenCuttingRopeDp: " << result << endl;

    result = MaximalProductWhenCuttingRopeDp(5);
    cout << "MaximalProductWhenCuttingRopeDp: " << result << endl;

    result = MaximalProductWhenCuttingRopeDp(10);
    cout << "MaximalProductWhenCuttingRopeDp: " << result << endl;
  }

  int MaximalProductWhenCuttingRopeRecurAux(int n)
  {
    if (n <= 1)
    {
      return 1;
    }


    int cur_max = 0;
    for (int i = 1; i < n; ++i)
    {

      cur_max = std::max({i * MaximalProductWhenCuttingRopeRecurAux(n - i),
                i * (n-i),
                cur_max});
    }

    return cur_max;
  }

  int MaximalProductWhenCuttingRopeRecur(int n)
  {
    return MaximalProductWhenCuttingRopeRecurAux(n);
  }

  int MaximalProductWhenCuttingRopeDp(int n)
  {
    vector<int> dp(n+1, 0);
    dp[2] = 1;
    for (int i = 3; i <= n; ++i)
    {
      int max = 0;
      for (int j = 1; j < i; ++j)
      {
        int val1 = j * (i - j);
        int val2 = j * dp[i-j];
        max = std::max({val1, val2, max});
      }
      dp[i] = max;
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
