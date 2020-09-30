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

  bool Aux(int node,
           vector<vector<bool>> &graph,
           unordered_set<int> &visited,
           unordered_set<int> &detected,
           stack<int> &st)
  {
    if (visited.count(node) != 0)
    {
      return false;
    }

    visited.insert(node);
    detected.insert(node);

    for (int i : graph[node])
    {
      if (detected.count(i) != 0)
      {
        return true;
      }

      if (Aux(i, graph, visited, detected, st))
      {
        return true;
      }
    }

    detected.erase(node);
    st.push(node);

    return false;
  }

  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<bool>> graph(numCourses, vector<bool>());
    for (int i = 0; i < prerequisites.size(); ++i)
    {
      graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    unordered_set<int> visited;
    unordered_set<int> detected;
    stack<int> st;

    for (int i = 0; i < numCourses; ++i)
    {
      if (visited.count(i) == 0)
      {
        if (Aux(i, graph, visited, detected, st))
        {
          return {};
        }
      }
    }

    vector<int> result;
    while (!st.empty())
    {
      result.push_back(st.top());
      st.pop();
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
