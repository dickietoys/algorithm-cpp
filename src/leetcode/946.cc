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

  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    if (pushed.empty() && popped.empty())
    {
      return true;
    }

    if (pushed.size() != popped.size())
    {
      return false;
    }
    int push_start = 0;
    int push_stop = pushed.size() - 1;
    int pop_start = 0;
    int pop_stop = popped.size() - 1;

    stack<int> st;
    while (true)
    {
      while (!st.empty() && st.top() == popped[pop_start])
      {
        st.pop();
        ++pop_start;
        continue;
      }

      if (pop_start > pop_stop)
      {
        return true;
      }

      if (push_start > push_stop)
      {
        return false;
      }

      st.push(pushed[push_start++]);
    }

    return true;
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
