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
    vector<vector<char>> input;
    bool result;

    input = {
      {'A','B','C','E'},
      {'S','F','C','S'},
      {'A','D','E','E'}
    };
    result = exist(input, "ABCCED");
    cout << "result: " << result << endl;
    assert(result == true);

    result = exist(input, "SEE");
    cout << "result: " << result << endl;
    assert(result == true);

    result = exist(input, "ABCB");
    cout << "result: " << result << endl;
    assert(result == false);
  }

  bool exist(vector<vector<char>>& board, string word) {
    set<string> s;
    int rowSize = board.size();
    int colSize = board[0].size();
    int wordSize = word.size();
    int wordPos = 0;
    bool found = false;
    for (int i = 0; i < rowSize; ++i)
    {
      for (int j = 0; j < colSize; ++j)
      {
        if (board[i][j] == word[wordPos])
        {
          if (dfsAux(board, i, j, word, wordPos))
          {
            return true;
          }
        }
      }
    }

    return false;
  }

  bool dfsAux(vector<vector<char>>& board, int xpos, int ypos, string word, int wordPos)
  {
    if (wordPos >= word.size())
    {
      return true;
    }

    if (xpos < 0 || xpos > board.size())
    {
      return false;
    }

    if (ypos < 0 || ypos > board[0].size())
    {
      return false;
    }

    bool result = false;
    if (board[xpos][ypos] == word[wordPos])
    {
      result = dfsAux(board, xpos - 1, ypos, word, wordPos+1) ||
               dfsAux(board, xpos + 1, ypos, word, wordPos+1) ||
               dfsAux(board, xpos, ypos - 1, word, wordPos+1) ||
               dfsAux(board, xpos, ypos + 1, word, wordPos+1);
      return result;
    }
    else
    {
      return false;
    }
  }

  string genKey(int xpos, int ypos)
  {
    return std::to_string(xpos).append(std::to_string(ypos));
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
