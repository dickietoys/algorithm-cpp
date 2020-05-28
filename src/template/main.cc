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

  void BFS(int vertex)
  {
    vector<bool> visited(vertex_nums_, false);
    deque<int> dq;
    dq.push_back(vertex);
    visited[vertex] = true;
    while (!dq.empty())
    {
      list<int> &vertex_node = list_graph_[vertex];
    }

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
  void RunTest()
  {
    Graph graph(5);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 4);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(1, 4);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.ShowByMatrix();
    cout << "====================================" << endl;
    graph.ShowByList();
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
