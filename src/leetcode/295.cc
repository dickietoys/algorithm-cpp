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
  }

  priority_queue<long, vector<long>, greater<long>> min_heap;
  priority_queue<long> max_heap;

  void addNum(int num) {
    if (min_heap.empty() || num >= min_heap.top())
    {
      min_heap.push(num);
    }
    else
    {
      max_heap.push(num);
    }

    if (min_heap.size() > max_heap.size() + 1)
    {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
    else if (max_heap.size() > min_heap.size() + 1)
    {
      min_heap.push(max_heap.top());
      max_heap.pop();
    }
  }

  double findMedian() {
    if (max_heap.empty() && min_heap.empty())
    {
      return 0;
    }

    if (max_heap.size() == min_heap.size())
    {
      return (max_heap.top() + min_heap.top()) / 2.0;
    }

    return max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
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
