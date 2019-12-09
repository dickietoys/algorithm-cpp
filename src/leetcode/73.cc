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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<vector<int>> input;
    int result;

    input = {
      {1, 1, 1},
      {1, 0, 1},
      {1, 1, 1}
    };
    setZeroes(input);
    Show(input);

    input = {
      {0, 1, 2, 0},
      {3, 4, 5, 2},
      {1, 3, 1, 5}
    };
    setZeroes(input);
    Show(input);
  }

  void setZeroes(vector<vector<int>>& matrix) {
    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    set<int> row;
    set<int> col;
    for (int i = 0; i < rowSize; ++i)
    {
      for (int j = 0; j < colSize; ++j)
      {
        if (matrix[i][j] == 0)
        {
          row.insert(i);
          col.insert(j);
        }
      }
    }

    for (auto it = row.begin(); it != row.end(); ++it)
    {
      for (int j = 0; j < colSize; ++j)
      {
        matrix[*it][j] = 0;
      }
    }

    for (auto it = col.begin(); it != col.end(); ++it)
    {
      for (int j = 0; j < rowSize; ++j)
      {
        matrix[j][*it] = 0;
      }
    }
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
