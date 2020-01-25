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
#include <bitset>

using namespace std;

class Solution {
 public:

  void RunTest()
  {
    vector<vector<int>> result = generate(5);
    Show(result);
  }

  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    Aux(result, 1, numRows);
    return result;
  }

  void Aux(vector<vector<int>> &result, int curRow, int numRows)
  {
    if (curRow > numRows)
    {
      return;
    }

    if (curRow == 1)
    {
      result.push_back({1});
    }
    else if (curRow == 2)
    {
      result.push_back({1, 1});
    }
    else
    {
      vector<int> item(curRow, 1);
      for (int i = 1; i < curRow - 1; ++i)
      {
        item[i] = result[curRow-2][i-1] + result[curRow-2][i];
      }
      result.push_back(item);
    }
    Aux(result, curRow + 1, numRows);
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
