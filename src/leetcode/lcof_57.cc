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
#include <functional>
#include <list>
#include <exception>

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
    输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

    序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

    示例 1：
    输入：target = 9
    输出：[[2,3,4],[4,5]]

    示例 2：
    输入：target = 15
    输出：[[1,2,3,4,5],[4,5,6],[7,8]]
  */
  vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> result;
    int max_value = (target + 1) / 2;

    int small = 1;
    int big = 2;
    int cur_value = small + big;
    while (small <= max_value)
    {
      if (cur_value == target)
      {
        vector<int> item;
        for (int i = small; i <= big; ++i)
        {
          item.push_back(i);
        }
        result.push_back(item);
      }

      while (cur_value > target)
      {
        cur_value = cur_value - small;
        ++small;

        if (cur_value == target)
        {
          vector<int> item;
          for (int i = small; i <= big; ++i)
          {
            item.push_back(i);
          }
          result.push_back(item);
        }
      }

      ++big;
      cur_value += big;
    }

    return result;
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
  delete solution;
  return 0;
}
