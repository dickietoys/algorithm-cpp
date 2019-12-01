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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    double input;
    double result;
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result(n, vector<string>(n, string(n, '.')));
    for (int i = 0; i < n; ++i)
    {
      vector<string> curBoard(n, string(n, '.'));
      for (int j = 0; j < n; ++j)
      {

      }
    }
  }

  bool isValid()

  void Show(vector<vector<string>> &result)
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
