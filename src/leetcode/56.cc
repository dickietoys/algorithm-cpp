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

  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty())
    {
      return {};
    }
    std::sort(intervals.begin(), intervals.end(), [] (vector<int> &lhs, vector<int> &rhs)
                                                  {
                                                    return lhs.front() < rhs.front();
                                                  });
    vector<vector<int>> result;
    int i = 0;
    int j = 1;
    while (j < intervals.size())
    {
      if (intervals[i].back() >= intervals[j].front())
      {
        intervals[j].front() = intervals[i].front();
        intervals[j].back() = std::max(intervals[j].back(), intervals[i].back());
        ++i;
        ++j;
      }
      else
      {
        result.push_back(intervals[i]);
        ++i;
        ++j;
      }
    }

    result.push_back(intervals.back());

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
