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
    bool result;

    input = {
      {1, 3, 5, 7},
      {10, 11, 16, 20},
      {23, 30, 34, 50}
    };
    result = searchMatrix(input, 3);
    cout << "result: " << result << endl;
    assert(result == true);

    input = {
      {1,   3,  5,  7},
      {10, 11, 16, 20},
      {23, 30, 34, 50}
    };
    result = searchMatrix(input, 13);
    cout << "result: " << result << endl;
    assert(result == false);
  }

  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0)
    {
      return 0;
    }

    if (matrix[0].size() == 0)
    {
      return 0;
    }
    int rowSize = matrix.size();
    int colSize =matrix[0].size();
    int low = 0;
    int high = rowSize - 1;
    while (low <= high)
    {
      int middle = (low + high) / 2;
      if (matrix[middle][0] > target)
      {
        high = middle - 1;
      }
      else if (matrix[middle][0] < target)
      {
        if (middle == rowSize - 1)
        {
          if (matrix[middle][colSize-1] >= target)
          {
            return Aux(matrix, target, middle);
          }
          else
          {
            break;
          }
        }
        else
        {
          if (matrix[middle+1][0] > target)
          {
            return Aux(matrix, target, middle);
          }
          else
          {
            low = middle + 1;
          }
        }
      }
      else
      {
        return true;
      }
    }

    return false;
  }

  bool Aux(vector<vector<int>>& matrix, int target, int row)
  {
    int colSize =matrix[0].size();
    int left = 0;
    int right = colSize - 1;
    while (left <= right)
    {
      int middle = (left + right) / 2;
      if (target == matrix[row][middle])
      {
        return true;
      }

      if (target > matrix[row][middle])
      {
        left = middle + 1;
      }
      else
      {
        right = middle - 1;
      }
    }

    return false;
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
