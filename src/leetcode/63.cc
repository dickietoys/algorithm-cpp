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
    vector<vector<int>> input;
    int result;

    input = {
      {0,0,0},
      {0,1,0},
      {0,0,0}
    };
    result = uniquePathsWithObstacles(input);
    cout << "result: " << result << endl;
    assert(result == 2);
  }

  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    return DpAux(obstacleGrid);
  }

  int DpAux(vector<vector<int>>& obstacleGrid)
  {
    int rowSize = obstacleGrid.size();
    int colSize = obstacleGrid[0].size();
    vector<vector<long>> dp(rowSize, vector<long>(colSize, 0));
    int value = 1;
    for (int i = 0; i < rowSize; ++i)
    {
      if (obstacleGrid[i][0])
      {
        value = 0;
      }
      dp[i][0] = value;
    }

    value = 1;
    for (int i = 0; i < colSize; ++i)
    {
      if (obstacleGrid[0][i])
      {
        value = 0;
      }
      dp[0][i] = value;
    }

    for (int i = 1; i < rowSize; ++i)
    {
      for (int j = 1; j < colSize; ++j)
      {
        if (obstacleGrid[i][j])
        {
          dp[i][j] = 0;
        }
        else
        {
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
      }
    }

    return dp[rowSize - 1][colSize - 1];
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
