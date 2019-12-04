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
    int input;
    vector<vector<int>> result;

    input = 3;
    result = generateMatrix(input);
    Show(result);
  }

  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    int rowStart = 0;
    int rowEnd = n - 1;
    int colStart = 0;
    int colEnd = n - 1;
    int value = 1;
    while (rowStart <= rowEnd && colStart <= colEnd)
    {
      for (int i = colStart; i <= colEnd; ++i)
      {
        result[rowStart][i] = value++;
      }
      ++rowStart;

      for (int i = rowStart; i <= rowEnd; ++i)
      {
        result[i][colEnd] = value++;
      }
      --colEnd;

      if (rowStart <= rowEnd)
      {
        for (int i = colEnd; i >= colStart; --i)
        {
          result[rowEnd][i] = value++;
        }

        --rowEnd;
      }

      if (colStart <= colEnd)
      {
        for (int i = rowEnd; i >= rowStart; --i)
        {
          cout << "value: " << value << endl;
          result[i][colStart] = value++;
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
