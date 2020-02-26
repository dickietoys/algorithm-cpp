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
    vector<vector<int>> input = {{2},
                                 {3, 4},
                                 {6,5,7},
                                 {4,1,8,3}};
    int result = minimumTotal(input);
    cout << "result: " << result << endl;
  }

  int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp(triangle.size() + 1, vector<int>(triangle.size() + 1, std::numeric_limits<int>::min()));
    return Aux(triangle, 0, 0, dp);
  }

  int Aux(vector<vector<int>>& triangle, int row, int pos, vector<vector<int>> &dp)
  {
    if (row >= triangle.size())
    {
      return 0;
    }

    int mid = 0;
    int right = 0;
    bool hasRight = false;
    if (pos + 1 <= row)
    {
      if (dp[row+1][pos+1] == std::numeric_limits<int>::min())
      {
        right = Aux(triangle, row + 1, pos + 1, dp) + triangle[row][pos+1];
      }
      else
      {
        right = dp[row+1][pos+1] + triangle[row][pos+1];
      }
      hasRight = true;
    }

    if (dp[row+1][pos] == std::numeric_limits<int>::min())
    {
      mid = Aux(triangle, row + 1, pos, dp) + triangle[row][pos];
    }
    else
    {
      mid = dp[row+1][pos] + triangle[row][pos];
    }

    if (hasRight)
    {
      int minValue = std::min(mid, right);
      dp[row][pos] = minValue;
      return minValue;
    }
    else
    {
      dp[row][pos] = mid;
      return mid;
    }
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
    }
    cout << endl;
  }

  template<class T>
  void Show(vector<vector<T>> &result)
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
