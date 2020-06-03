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
#include <list>

using namespace std;

class Graph
{
 public:
  int vertex_nums_;
  vector<vector<bool>> matrix_graph_;
  vector<list<int>> list_graph_;

  Graph(int vertex_nums)
      : vertex_nums_(vertex_nums)
      , matrix_graph_(vertex_nums, vector<bool>(vertex_nums, false))
      , list_graph_(vertex_nums)
  {}

  void AddEdge(int src_vertex, int dst_vertex)
  {
    matrix_graph_[src_vertex][dst_vertex] = true;
    list<int> &vertex_node = list_graph_[src_vertex];
    if (std::find(vertex_node.begin(), vertex_node.end(), dst_vertex) == vertex_node.end())
    {
      vertex_node.push_back(dst_vertex);
    }
  }

  vector<int> BFS(int vertex)
  {
    vector<int> result;
    vector<bool> visited(vertex_nums_, false);
    deque<int> dq;
    dq.push_back(vertex);
    visited[vertex] = true;
    result.push_back(vertex);
    while (!dq.empty())
    {
      int cur_vertex = dq.front();
      dq.pop_front();
      list<int> &vertex_node = list_graph_[cur_vertex];
      for (int n : vertex_node)
      {
        if (!visited[n])
        {
          visited[n] = true;
          result.push_back(n);
          dq.push_back(n);
        }
      }
    }

    return result;
  }

  void DFSAux(int vertex, vector<bool> &visited, vector<int> &result)
  {
    if (visited[vertex])
    {
      return;
    }

    visited[vertex] = true;
    result.push_back(vertex);

    list<int> &vertex_list = list_graph_[vertex];
    for (int n : vertex_list)
    {
      DFSAux(n, visited, result);
    }
  }
  vector<int> DFS(int vertex)
  {
    vector<bool> visited(vertex_nums_, false);
    vector<int> result;
    DFSAux(vertex, visited, result);

    return result;
  }

  bool HasCycleAux(int vertex, vector<int> &visited, set<int> &path)
  {
    if (visited[vertex])
    {
      return true;
    }

    if (path.count(vertex))
    {
      return true;
    }

    path.insert(vertex);
    visited[vertex] = true;
    list<int> &l = list_graph_[vertex];
    for (int n : l)
    {
      if (path.count(n))
      {
        return true;
      }

      if (HasCycleAux(n, visited, path))
      {
        return true;
      }
    }

    path.erase(vertex);
    return false;
  }

  bool HasCycle()
  {
    vector<int> visited(vertex_nums_, false);
    set<int> path;
    for (int i = 0; i < vertex_nums_; ++i)
    {
      if (!visited[i])
      {
        if (HasCycleAux(i, visited, path))
        {
          return true;
        }
      }
    }

    return false;
  }

  void TopoSortAux(int vertex, vector<int> &visited, stack<int> &result)
  {
    if (visited[vertex])
    {
      return;
    }

    visited[vertex] = true;
    for (int n : list_graph_[vertex])
    {
      TopoSortAux(n, visited, result);
    }
    result.push(vertex);
  }

  vector<int> TopoSort()
  {
    vector<int> visited(vertex_nums_, false);
    stack<int> st;
    for (int i = 0; i < vertex_nums_; ++i)
    {
      if (!visited[i])
      {
        TopoSortAux(i, visited, st);
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

  void ShowByMatrix()
  {
    for (int i = 0; i < matrix_graph_.size(); ++i)
    {
      cout << i << " -> ";
      for (int j = 0; j < matrix_graph_[i].size(); ++j)
      {
        if (matrix_graph_[i][j])
        {
          cout << j << " -> ";
        }
      }
      cout << "end" << endl;
    }
  }

  void ShowByList()
  {
    for (int i = 0; i < list_graph_.size(); ++i)
    {
      cout << i << " -> ";
      for (int j : list_graph_[i])
      {
          cout << j << " -> ";
      }
      cout << "end" << endl;
    }
  }
};

class Solution {
 public:

  void TestDfsAndBfs()
  {
    Graph graph(4);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 0);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 3);
    cout << "==============ShowByMatrix=================" << endl;
    graph.ShowByMatrix();
    cout << "==============ShowByList=================" << endl;
    graph.ShowByList();
    cout << "==============BFS=================" << endl;
    vector<int> bfs_result = graph.BFS(2);
    Show(bfs_result);
    cout << "==============BFS=================" << endl;
    vector<int> dfs_result = graph.DFS(2);
    Show(dfs_result);
  }

  void TestDetectCycleDirected()
  {
    Graph graph(4);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 0);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 3);
    if (graph.HasCycle())
    {
      cout << "contains cycle" << endl;
    }
    else
    {
      cout << "doesn't contains cycle" << endl;
    }
  }

  void TestTopoSort()
  {
    Graph graph(6);
    graph.AddEdge(5, 2);
    graph.AddEdge(5, 0);
    graph.AddEdge(4, 0);
    graph.AddEdge(4, 1);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 1);
    vector<int> result = graph.TopoSort();
    Show(result);
  }

  void RunTest()
  {
    TestTopoSort();
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", " << endl;
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
        cout << result[i][j] << ", " << endl;
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
