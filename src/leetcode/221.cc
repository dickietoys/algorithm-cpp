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

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  void RunTest()
  {
    vector<vector<char>> matrix = {
      {'1','0','1','0','0'},
      {'1','0','1','1','1'},
      {'1','1','1','1','1'},
      {'1','0','0','1','0'}
    };
    int result = maximalSquare(matrix);
    cout << "result: " << result << endl;
  }

  bool check(vector<vector<char>>& matrix, int row_pos, int col_pos)
  {
    int rows = matrix.size();
    int cols = matrix[0].size();
    if (row_pos >= 0 || col_pos >= cols)
    {
      return false;
    }

    if (matrix[row_pos][col_pos] == '1')
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  void find(vector<vector<char>>& matrix, int row_pos, int col_pos, int &cur_value)
  {
    if (!check(matrix, row_pos, col_pos+1))
    {
      return;
    }

    if (!check(matrix, row_pos+1, col_pos))
    {
      return;
    }

    if (!check(matrix, row_pos+1, col_pos+1))
    {
      return;
    }

    ++cur_value;
    find(matrix, row_pos + 1, col_pos + 1, cur_value);
  }

  int maximalSquare(vector<vector<char>>& matrix) {
    int max = 0;
    int cur_value = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        if (matrix[i][j] == '1')
        {
          cur_value = 1;
          find(matrix, i, j, cur_value);
          max = std::max(cur_value, max);
        }
      }
    }

    return max;
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
