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

  int LongestPathInMatrixRecurAux(vector<vector<int>> arr, int xpos, int ypos, int prev_value)
  {
    int row_size = arr.size();
    int col_size = arr[0].size();
    if (!IsValidPos(xpos, ypos, row_size, col_size) || arr[xpos][ypos] - prev_value != 1)
    {
      return 0;
    }

    int cur_size =  std::max({LongestPathInMatrixRecurAux(arr, xpos+1, ypos, arr[xpos][ypos]),
                    LongestPathInMatrixRecurAux(arr, xpos-1, ypos, arr[xpos][ypos]),
                    LongestPathInMatrixRecurAux(arr, xpos, ypos+1, arr[xpos][ypos]),
                    LongestPathInMatrixRecurAux(arr, xpos, ypos-1, arr[xpos][ypos])}) + 1;
    return cur_size;
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

    int max = 0;
    for (int i = 0; i < row_size; ++i)
    {
      for (int j = 0; j < col_size; ++j)
      {
        max = std::max(max, LongestPathInMatrixRecurAux(arr, i, j, arr[i][j] - 1));
      }
    }

    return max;
  }

  int LongestPathInMatrixDpAux(vector<vector<int>> arr,
                               int xpos,
                               int ypos,
                               int prev_value,
                               vector<vector<int>> &dp)
  {
    int row_size = arr.size();
    int col_size = arr[0].size();
    if (!IsValidPos(xpos, ypos, row_size, col_size) || arr[xpos][ypos] - prev_value != 1)
    {
      return 0;
    }

    if (dp[xpos][ypos] != -1)
    {
      return dp[xpos][ypos];
    }

    int cur_size =  std::max({LongestPathInMatrixRecurAux(arr, xpos+1, ypos, arr[xpos][ypos]),
                    LongestPathInMatrixRecurAux(arr, xpos-1, ypos, arr[xpos][ypos]),
                    LongestPathInMatrixRecurAux(arr, xpos, ypos+1, arr[xpos][ypos]),
                    LongestPathInMatrixRecurAux(arr, xpos, ypos-1, arr[xpos][ypos])}) + 1;
    dp[xpos][ypos] = cur_size;
    return cur_size;
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

    vector<vector<int>> dp(row_size, vector<int>(col_size, -1));
    int max = 0;
    for (int i = 0; i < row_size; ++i)
    {
      for (int j = 0; j < col_size; ++j)
      {
        max = std::max(max, LongestPathInMatrixDpAux(arr, i, j, arr[i][j] - 1, dp));
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
