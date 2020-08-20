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
  }

  /*
    11011

    10100   10199
    09100   09199

    11111

    11100   11111
    10100   10199

    11211
    11100   11199
  */
  int countDigitOne(int n) {
    int count = 0;
    for (long factor = 1; factor <= n; factor = factor * 10)
    {
      int first = n / factor;
      int second = n % factor;
      int digit = first % 10;
      if (digit == 0)
      {
        count += first / 10 * factor;
      }
      else if (digit == 1)
      {
        count += first / 10 * factor + second + 1;
      }
      else
      {
        count += (first / 10 + 1) * factor;
      }
    }

    return count;
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
