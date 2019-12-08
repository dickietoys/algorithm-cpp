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

    int xpos = 0;
    int ypos = 0;
    int wordPos = 0;
    while (xpos < rowSize && ypos < colSize)
    {
      if (board[xpos][ypos] == word[wordPos] && !s.count(genKey(xpos, ypos)))
      {
        ++wordPos;
        s.insert(genKey(xpos, ypos));
      }
      else
      {
        if (xpos == 0)
        {

        }
      }
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
