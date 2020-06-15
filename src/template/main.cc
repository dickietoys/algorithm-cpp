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
    int result = LongestPathInMatrixRecur(
        {
          {1, 2, 9},
          {5, 3, 8},
          {4, 6, 7}
        });
    cout << "LongestPathInMatrixRecur: " << result << endl;
    cout << "==================dp======================" << endl;
    result = LongestPathInMatrixDp(
        {
          {1, 2, 9},
          {5, 3, 8},
          {4, 6, 7}
        });
    cout << "LongestPathInMatrixDp: " << result << endl;
  }

  int max_;

  bool IsValidPos(int xpos, int ypos, int rows, int cols)
  {
    if (xpos < 0 || xpos >= rows || ypos < 0 || ypos >= cols)
    {
      return false;
    }
    else
    {
      return true;
    }
  }

  void LongestPathInMatrixRecurAux(vector<vector<int>> arr, int xpos, int ypos, int prev_value, int cur_size)
  {
    int row_size = arr.size();
    int col_size = arr[0].size();
    if (!IsValidPos(xpos, ypos, row_size, col_size))
    {
      max_ = std::max(cur_size, max_);
      return;
    }

    if (cur_size == 0 || arr[xpos][ypos] - prev_value == 1)
    {
      ++cur_size;
      LongestPathInMatrixRecurAux(arr, xpos+1, ypos, arr[xpos][ypos], cur_size);
      LongestPathInMatrixRecurAux(arr, xpos-1, ypos, arr[xpos][ypos], cur_size);
      LongestPathInMatrixRecurAux(arr, xpos, ypos+1, arr[xpos][ypos], cur_size);
      LongestPathInMatrixRecurAux(arr, xpos, ypos-1, arr[xpos][ypos], cur_size);
    }
  }

  int LongestPathInMatrixRecur(vector<vector<int>> arr)
  {
    int row_size = arr.size();
    if (row_size == 0)
    {
      return 0;
    }
    int col_size = arr[0].size();
    if (col_size == 0)
    {
      return 0;
    }

    max_ = 0;
    for (int i = 0; i < row_size; ++i)
    {
      for (int j = 0; j < col_size; ++j)
      {
        LongestPathInMatrixRecurAux(arr, i, j, 0, 0);
      }
    }

    return max_;
  }

  int LongestPathInMatrixDp(vector<vector<int>> arr)
  {
    int row_size = arr.size();
    if (row_size == 0)
    {
      return 0;
    }
    int col_size = arr[0].size();
    if (col_size == 0)
    {
      return 0;
    }

    vector<vector<int>> dp(row_size, vector<int>(col_size, 1));
    for (int i = 1; i < row_size; ++i)
    {
      if (arr[i][0] - arr[i-1][i-1])
      {
        dp[i][0] =
      }
    }
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
