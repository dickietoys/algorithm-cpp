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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<vector<int>> input;
    vector<int> result;

    input = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
    };
    result = spiralOrder(input);
    Show(result);


    input = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
    };
    result = spiralOrder(input);
    Show(result);
  }

  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.size() == 0)
    {
      return result;
    }

    int rowStart = 0;
    int rowEnd = matrix.size() - 1;
    int colStart = 0;
    int colEnd = matrix[0].size() - 1;
    while (rowStart <= rowEnd && colStart <= colEnd)
    {
      cout << "rowStart: " << rowStart << "; rowEnd: " << rowEnd << endl;
      cout << "colStart: " << colStart << "; colEnd: " << colEnd << endl;
      for (int colPos = colStart; colPos <= colEnd; ++colPos)
      {
        result.push_back(matrix[rowStart][colPos]);
      }
      ++rowStart;

      for (int rowPos = rowStart; rowPos <= rowEnd; ++rowPos)
      {
        result.push_back(matrix[rowPos][colEnd]);
      }
      --colEnd;

      if (rowStart <= rowEnd)
      {
        for (int colPos = colEnd; colPos >= colStart; --colPos)
        {
          result.push_back(matrix[rowEnd][colPos]);
        }
        --rowEnd;
      }

      if (colStart <= colEnd)
      {
        for (int rowPos = rowEnd; rowPos >= rowStart; --rowPos)
        {
          result.push_back(matrix[rowPos][colStart]);
        }
        ++colStart;
      }
    }

    return result;
  }

  void Show(vector<int> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
