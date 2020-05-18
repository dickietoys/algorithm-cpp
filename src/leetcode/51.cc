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

class Solution {
 public:
  void RunTest()
  {
    vector<vector<string>> result = solveNQueens(4);
    Show(result);
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> board(n, vector<string>(n, "."));
    vector<vector<string>> result;
    Aux(board, n, 0, result);

    return result;
  }

  bool IsValid(vector<vector<string>> &board, int n, int row_pos, int col_pos)
  {
    for (int i = row_pos, j = col_pos; i >= 0 && j >= 0; --i, --j)
    {
      if (board[i][j] == "Q")
      {
        return false;
      }
    }

    for (int i = row_pos, j = col_pos; i >= 0 && j < n; --i, ++j)
    {
      if (board[i][j] == "Q")
      {
        return false;
      }
    }

    for (int i = row_pos; i >= 0; --i)
    {
      if (board[i][col_pos] == "Q")
      {
        return false;
      }
    }

    return true;
  }

  void CopyBoard2Result(vector<vector<string>> &board, vector<vector<string>> &result)
  {
    vector<string> tmp;
    for (vector<string> &row_data : board)
    {
      string item = "";
      for (string &s : row_data)
      {
        item += s;
      }
      tmp.push_back(item);
    }
    result.push_back(tmp);
  }

  bool Aux(vector<vector<string>> &board, int n, int row_pos, vector<vector<string>> &result)
  {
    if (row_pos >= n)
    {
      return true;
    }

    for (int i = 0; i < n; ++i)
    {
      if (IsValid(board, n, row_pos, i))
      {
        board[row_pos][i] = "Q";
        if (Aux(board, n, row_pos + 1, result))
        {
          CopyBoard2Result(board, result);
          board[row_pos][i] = ".";
        }
        else
        {
          board[row_pos][i] = ".";
        }
      }
    }

    return false;
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", " << endl;
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
        cout << result[i][j] << ", " << endl;
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
