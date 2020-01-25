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
    char X = 'X';
    char O = 'O';
    vector<vector<char>> board = {
      {X, X, X, X},
      {X, O, O, X},
      {X, X, O, X},
      {X, O, X, X},
    };
    solve(board);
  }

  void solve(vector<vector<char>>& board) {
    int rows = board.size();
    if (rows == 0)
    {
      return;
    }
    int cols = board[0].size();

    for (int i = 0; i < rows; ++i)
    {
      Check(board, i, 0, rows, cols);
      if (cols > 1)
      {
        Check(board, i, cols - 1, rows, cols);
      }
    }

    for (int i = 1; i < cols - 1; ++i)
    {
      Check(board, 0, i, rows, cols);
      if (rows > 1)
      {
        Check(board, rows-1, i, rows, cols);
      }
    }

    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        if (board[i][j] == 'O')
        {
          board[i][j] = 'X';
        }
      }
    }

    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        if (board[i][j] == 'F')
        {
          board[i][j] = 'O';
        }
      }
    }
  }

  void Check(vector<vector<char>>& board, int i, int j, int rows, int cols)
  {
    if (board[i][j] == 'O')
    {
      board[i][j] = 'F';
      if (j > 0)
      {
        Check(board, i, j - 1, rows, cols);
      }

      if (j < cols - 1)
      {
        Check(board, i, j + 1, rows, cols);
      }

      if (i > 0)
      {
        Check(board, i - 1, j, rows, cols);
      }

      if (i < rows - 1)
      {
        Check(board, i + 1, j, rows, cols);
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
