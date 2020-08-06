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

class Node {
 public:
  int val;
  vector<Node*> neighbors;

  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }

  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }

  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  void RunTest()
  {
    vector<vector<char>> board = {
      {'5','3','.','.','7','.','.','.','.'},
      {'6','.','.','1','9','5','.','.','.'},
      {'.','9','8','.','.','.','.','6','.'},
      {'8','.','.','.','6','.','.','.','3'},
      {'4','.','.','8','.','3','.','.','1'},
      {'7','.','.','.','2','.','.','.','6'},
      {'.','6','.','.','.','.','2','8','.'},
      {'.','.','.','4','1','9','.','.','5'},
      {'.','.','.','.','8','.','.','7','9'}};

    solveSudoku(board);
    Show(board);
  }

  bool isValidSudoku(vector<vector<char>>& board, int row_pos, int col_pos, char count) {
    for (int i = 0; i < board.size(); ++i)
    {
      if (board[row_pos][i] == count)
      {
        return false;
      }
    }

    for (int i = 0; i < board.size(); ++i)
    {
      if (board[i][col_pos] == count)
      {
        return false;
      }
    }

    row_pos = row_pos / 3 * 3;
    col_pos = col_pos / 3 * 3;

    for (int i = 0; i < 3; ++i)
    {
      int x_pos = row_pos + i;
      for (int j = 0; j < 3; ++j)
      {
        int y_pos = col_pos + j;
        if (board[x_pos][y_pos] == count)
        {
          return false;
        }
      }
    }

    return true;
  }

  bool Aux(vector<vector<char>>& board)
  {
    for (int i = 0; i < board.size(); ++i)
    {
      for (int j = 0; j < board.size(); ++j)
      {
        if (board[i][j] == '.')
        {
          char count = '1';
          while (count <= '9')
          {
            if (isValidSudoku(board, i, j, count))
            {
              board[i][j] = count;

              if (Aux(board))
              {
                return true;
              }
              else
              {
                board[i][j] = '.';
              }
            }
            ++count;
          }
          return false;
        }
      }
    }

    return true;
  }

  void solveSudoku(vector<vector<char>>& board) {
    Aux(board);
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
  delete solution;
  return 0;
}
