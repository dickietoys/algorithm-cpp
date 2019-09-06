#ifndef GRAPH_CONTAINER_H_
#define GRAPH_CONTAINER_H_

#include <vector>
#include <queue>
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
      dist_(vector<int>(vertexNum, -1)),
      path_(vector<int>(vertexNum, -1))
  {}

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

  void BFS(int src, int dst)
  {
    src = src - 1;
    dst = dst - 1;
    queue<int> q;
    q.push(src);
    dist_[src] = 0;
    while (!q.empty())
    {
      src = q.front();
      q.pop();
      for (int i = 0; i < graph_.size(); ++i)
      {
        dst = arr_[src][i];
        if (dst != 0 && color[dst] == 0)
        {
          color[dst] = 1;
          dist[dst] = dist[src] + 1;
          path[dst] = src;
          q.push(dst);
        }
      }
      color[src] = 2;
    }

    for (int i = 0; i < arrSize_; ++i)
    {
      cout << "dist[" << i << "] : " << dist[i] << ", " << endl;
    }

    for (int i = 0; i < arrSize_; ++i)
    {
      cout << "color[" << i << "] : " << color[i] << ", " << endl;
    }


    cout << "from " << src << " to " << dst << " distance is " << dist[dst] << endl;
  }

  void doDFS()
  {

  }

  void DFS()
  {

    for (int i = 0; i < arrSize_; ++i)
    {
      color[arrSize_] = 0;
      path[arrSize_] = -1;
    }
  }

  void showGraph()
  {
    for (int i = 0; i < arrSize_; ++i)
    {
      for (int j = 0; j < arrSize_; ++j)
      {
        cout << arr_[i][j] << ", ";
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
