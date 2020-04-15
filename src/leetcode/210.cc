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

  bool Visit(vector<vector<int>> &g,
             int vertex,
             vector<bool> &visited,
             vector<bool> &detected,
             vector<int> &result)
  {
    if (visited[vertex])
    {
      return false;
    }

    if (detected[vertex])
    {
      return true;
    }

    visited[vertex] = true;
    detected[vertex] = true;
    for (auto i : g[vertex])
    {
      if (detected[i])
      {
        return true;
      }

      if (Visit(g, i, visited, detected, result))
      {
        return true;
      }
    }

    detected[vertex] = false;
    result.push_back(vertex);

    return false;
  }

  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(numCourses);
    for (auto v : prerequisites)
    {
      for (int i = 1; i < v.size(); ++i)
      {
        g[v[0]].push_back(v[i]);
      }
    }

    vector<bool> visited(numCourses, false);
    vector<bool> detected(numCourses, false);
    vector<int> result;
    for (int i = 0; i < numCourses; ++i)
    {
      if (!visited[i])
      {
        if (Visit(g, i, visited, detected, result))
        {
          return vector<int>();
        }
      }
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

  return 0;
}
