#ifndef GRAPH_CONTAINER_H_
#define GRAPH_CONTAINER_H_

#include <vector>
#include <queue>
#include <stack>
#include <ostream>
#include <iostream>
#include <cstring>

using namespace std;

class GraphAdjacentArray{
 public:
  GraphAdjacentArray()
  {}

  GraphAdjacentArray(int vertexNum):
      graph_(vector<vector<int>>(vertexNum, vector<int>(vertexNum, 0))),
      color_(vector<int>(vertexNum, 0)),
      path_(vector<int>(vertexNum, -1)),
      dist_(vector<int>(vertexNum, -1))
  {
    cout << "color_.size(): " << color_.size() << endl;
    cout << "dist_.size(): " << dist_.size() << endl;
    cout << "path_.size(): " << path_.size() << endl;
  }

  void setVertexRelation(int src, int dst)
  {
    graph_[src-1][dst-1] = 1;
  }

  ~GraphAdjacentArray()
  {}

  void resetAuxData()
  {
    color_.assign(color_.size(), 0);
    dist_.assign(dist_.size(), -1);
    path_.assign(path_.size(), -1);
  }

  void BFS(int from, int to)
  {
    int src = from - 1;
    queue<int> q;
    q.push(src);
    dist_[src] = 0;
    while (!q.empty())
    {
      src = q.front();
      q.pop();
      for (size_t i = 0; i < graph_.size(); ++i)
      {
        if (graph_[src][i] != 0 && color_[i] == 0)
        {
          color_[i] = 1;
          dist_[i] = dist_[src] + 1;
          path_[i + 1] = src + 1;
          q.push(i);
        }
      }
      color_[src] = 2;
    }
    cout << "from " << from << " to " << to << " distance is " << dist_[to-1] << endl;
    cout << "path is :";
    int node = to;
    stack<int> pathStack;
    pathStack.push(node);
    while(path_[node] != -1)
    {
      node = path_[node];
      pathStack.push(node);
    }

    while (!pathStack.empty())
    {
      cout << pathStack.top() << ", ";
      pathStack.pop();
    }
    cout << endl;
  }

  void DFS()
  {
    for (size_t i = 0; i < graph_.size(); ++i)
    {
      if (color_[i] == 0)
      {
        doDFS(i);
        stack<int> pathStack;
        for (size_t i = 0; i < graph_.size(); ++i)
        {
          int node = i + 1;
          pathStack.push(node);
          while(path_[node] != -1)
          {
            node = path_[node];
            pathStack.push(node);
          }

          // print the path
          cout << "one path :";
          while (!pathStack.empty())
          {
            cout << pathStack.top() << ", ";
            pathStack.pop();
          }
          cout << endl;
        }
      }
    }
  }

  void doDFS(int node)
  {
    color_[node] = 1;
    for (size_t i = 0; i < graph_.size(); ++i)
    {
      if (graph_[node][i] == 1 && color_[i] == 0)
      {
        path_[i + 1] = node + 1;
        doDFS(i);
      }
    }
    color_[node] = 2;
  }

  void showGraph()
  {
    for (size_t i = 0; i < graph_.size(); ++i)
    {
      for (size_t j = 0; j < graph_[i].size(); ++j)
      {
        cout << graph_[i][j] << ", ";
      }
      cout << endl;
    }
  }

  vector<vector<int>> graph_;
  vector<int> color_;
  vector<int> path_;
  vector<int> dist_;
};


class GraphAdjacentList{
 public:
};

#endif
