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
#include <queue>

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
    int result = nthUglyNumber(10);
    cout << result << endl;
  }

  int nthUglyNumber(int n) {
    if (n <= 0)
    {
      return 0;
    }
    vector<int> result(n, 0);
    result[0] = 1;
    int two_pos = 0;
    int three_pos = 0;
    int five_pos = 0;
    for (int i = 1; i < n; ++i)
    {
      result[i] = std::min({result[two_pos] * 2, result[three_pos] * 3, result[five_pos] * 5});
      if (result[i] == result[two_pos] * 2)
      {
        ++two_pos;
      }
      if (result[i] == result[three_pos] * 3)
      {
        ++three_pos;
      }
      if (result[i] == result[five_pos] * 5)
      {
        ++five_pos;
      }
    }

    return result[n-1];
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
