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
    vector<vector<int>> input;

    input = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
    };

    rotate(input);
    Show(input);
  }

  void rotate(vector<vector<int>>& matrix) {
    int size = matrix.size();
    for (int i = 0; i < size / 2; ++i)
    {
      for (int j = i; j < size - i - 1; ++j)
      {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[size - j - 1][i];
        matrix[size - j - 1][i] = matrix[size - i - 1][size - j - 1];
        matrix[size - i - 1][size - j - 1] = matrix[j][size - i - 1];
        matrix[j][size - i - 1] = tmp;
      }
    }
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
