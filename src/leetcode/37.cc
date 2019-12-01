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
    solveSudoku(input);
    show(input);
  }

  void solveSudoku(vector<vector<char>>& board) {

  }

  void show(vector<vector<char>>& board)
  {
    for (size_t i = 0; i < board.size(); ++i)
    {
      for (size_t j = 0; j < board[i].size(); ++j)
      {
        cout << board[i][j] << ", ";
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
