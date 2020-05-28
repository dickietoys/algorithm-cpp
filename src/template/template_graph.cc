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
    list<int> vertex_node = list_graph_[src_vertex];
    if (std::find(vertex_node.begin(), vertex_node.end(), dst_vertex) != vertex_node.end())
    {
      list_graph_[src_vertex].push_back(dst_vertex);
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
