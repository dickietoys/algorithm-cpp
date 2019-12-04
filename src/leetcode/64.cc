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
      {1,3,1},
      {1,5,1},
      {4,2,1}
    };
    result = minPathSum(input);
    cout << "result: " << result << endl;
    assert(result == 7);
  }

  int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
    int rowSize = grid.size();
    int colSize = grid[0].size();
    dp[0][0] = grid[0][0];
    for (int i = 1; i < rowSize; ++i)
    {
      dp[i][0] = grid[i][0] + dp[i-1][0];
    }

    for (int i = 1; i < colSize; ++i)
    {
      dp[0][i] = grid[0][i] + dp[0][i-1];
    }

    for (int i = 1; i < rowSize; ++i)
    {
      for (int j = 1; j < colSize; ++j)
      {
        dp[i][j] = std::min(dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j]);
      }
    }

    return dp[rowSize-1][colSize-1];
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
