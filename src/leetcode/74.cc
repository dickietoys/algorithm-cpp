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
    if (matrix.empty() || matrix[0].empty())
    {
      return false;
    }
    int rows = matrix.size() - 1;
    int cols = matrix[0].size() - 1;
    int low = 0;
    int high = rows;
    int pos = -1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (matrix[mid][0] > target)
      {
        // 在上面
        high = mid - 1;
      }
      else
      {
        //在本行或在下面
        if ((matrix[mid][cols] >= target))
        {
          pos = mid;
          break;
        }
        else
        {
          low = mid + 1;
        }
      }
    }

    if (pos == -1)
    {
      return false;
    }

    low = 0;
    high = cols;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (matrix[pos][mid] == target)
      {
        return true;
      }
      else if (matrix[pos][mid] > target)
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
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
