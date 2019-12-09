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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    int input;
    int result;

    result = climbStairs(2);
    cout << "result: " << result << endl;
    assert(result == 2);

    result = climbStairs(3);
    cout << "result: " << result << endl;
    assert(result == 3);
  }

  int climbStairs(int n) {
    return dpAux(n);
  }

  int dpAux(int n)
  {
    if (n == 0)
    {
      return 0;
    }
    else if (n == 1)
    {
      return 1;
    }
    else if (n == 2)
    {
      return 2;
    }

    vector<int> bookmark(n + 1, 0);
    bookmark[0] = 0;
    bookmark[1] = 1;
    bookmark[2] = 2;
    for (int i = 3; i <= n; ++i)
    {
      bookmark[i] = bookmark[i-1] + bookmark[i-2];
    }

    return bookmark[n];
  }

  int Aux(int n)
  {
    if (n == 0)
    {
      return 1;
    }

    if (n < 0)
    {
      return 0;
    }

    return Aux(n - 1) + Aux(n - 2);
  }

  void Show(vector<string> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
  }

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
