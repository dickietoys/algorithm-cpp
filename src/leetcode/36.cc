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

using namespace std;

class Solution {
public:
  void RunTest()
  {
    vector<vector<char>> input = {};
    bool result = 0;
    input = {
      {'5','3','.','.','7','.','.','.','.'},
      {'6','.','.','1','9','5','.','.','.'},
      {'.','9','8','.','.','.','.','6','.'},
      {'8','.','.','.','6','.','.','.','3'},
      {'4','.','.','8','.','3','.','.','1'},
      {'7','.','.','.','2','.','.','.','6'},
      {'.','6','.','.','.','.','2','8','.'},
      {'.','.','.','4','1','9','.','.','5'},
      {'.','.','.','.','8','.','.','7','9'}
    };
    result = isValidSudoku(input);
    assert(result == true);
  }

  bool isValidSudoku(vector<vector<char>>& board) {
    int length = board.size();
    unordered_set<char> uoset;
    for (int i = 0; i < length; ++i)
    {
      uoset.clear();
      for (int j = 0; j < length; ++j)
      {
        if (board[i][j] >= '1' && board[i][j] <= '9')
        {
          if (uoset.count(board[i][j]) == 0)
          {
            uoset.insert(board[i][j]);
          }
          else
          {
            return false;
          }
        }
      }
    }

    for (int i = 0; i < length; ++i)
    {
      uoset.clear();
      for (int j = 0; j < length; ++j)
      {
        if (board[j][i] >= '1' && board[j][i] <= '9')
        {
          if (uoset.count(board[j][i]) == 0)
          {
            uoset.insert(board[j][i]);
          }
          else
          {
            return false;
          }
        }
      }
    }

    for (int i = 0; i < length; i += 3)
    {
      for (int j = 0; j < length; j += 3)
      {
        uoset.clear();
        for (int k = 0; k < 3; ++k)
        {
          for (int l =0; l < 3; ++l)
          {
            if (board[i+k][j+l] >= '1' && board[i+k][j+l] <= '9')
            {
              if (uoset.count(board[i+k][j+l]) == 0)
              {
                uoset.insert(board[i+k][j+l]);
              }
              else
              {
                return false;
              }
            }
          }
        }
      }
    }

    return true;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
