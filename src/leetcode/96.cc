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
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

  void RunTest()
  {
    int input;
    int result;

    input = 3;
    result = numTrees(input);
    cout << "result: " << result << endl;
    assert(result == 5);
  }

  int numTrees(int n) {
    // vector<int> bookmark(n+1, -1);
    // bookmark[0] = 1;
    // bookmark[1] = 1;
    // return Aux(n, bookmark);
    return DpAux(n);
  }

  int DpAux(int n)
  {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
      for (int j = 0; j < i; ++j)
      {
        dp[i] += dp[j] * dp[i-j-1];
      }
    }

    return dp[n];
  }

  int Aux(int n, vector<int> &bookmark)
  {
    if (bookmark[n] != -1)
    {
      return bookmark[n];
    }

    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
      sum += Aux(i - 1, bookmark) * Aux(n - i, bookmark);
    }

    bookmark[n] = sum;
    return sum;
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
