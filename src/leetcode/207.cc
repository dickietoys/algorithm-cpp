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

  bool hasCycle(vector<vector<int>> &g,
                int vertex,
                vector<bool> &visted,
                vector<bool> &detected)
  {
    if (visted[vertex])
    {
      return false;
    }

    if (detected[vertex])
    {
      return true;
    }

    visted[vertex] = true;
    detected[vertex] = true;
    for (auto it : g[vertex])
    {
      if (detected[it])
      {
        return true;
      }

      if (hasCycle(g, it, visted, detected))
      {
        return true;
      }
    }

    detected[vertex] = false;
    return false;
  }

  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(numCourses, vector<int>());
    for (auto courses : prerequisites)
    {
      int vertex = courses[0];
      for (int i = 1; i < courses.size(); ++i)
      {
        g[vertex].push_back(courses[i]);
      }
    }

    vector<bool> visted(numCourses, false);
    vector<bool> detected(numCourses, false);
    for (int i = 0; i < numCourses; ++i)
    {
      if (!visted[i])
      {
        if (hasCycle(g, i, visted, detected))
        {
          return false;
        }
      }
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

  return 0;
}
