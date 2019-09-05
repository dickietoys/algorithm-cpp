#ifndef GRAPH_CONTAINER_H_
#define GRAPH_CONTAINER_H_

#include <vector>
#include <queue>
#include <ostream>
#include <iostream>

using namespace std;

class GraphAdjacentArray{
 public:
  GraphAdjacentArray()
  {}

  GraphAdjacentArray(int vertexNum):arrSize_(vertexNum)
  {
    arr_ = new int*[vertexNum];
    for (int i = 0; i < vertexNum; ++i)
    {
      arr_[i] = new int[vertexNum];
    }
  }

  void setVertexRelation(int src, int dst)
  {
    arr_[src-1][dst-1] = 1;
  }

  ~GraphAdjacentArray()
  {
    for (int i = 0; i < arrSize_; ++i)
    {
      delete[] arr_[i];
    }

    delete[] arr_;
  }

  void BFS(int from, int to)
  {
    int dist[arrSize_];
    int path[arrSize_];
    int color[arrSize_];
    for (int i = 0; i < arrSize_; ++i)
    {
      dist[i] = -1;
      path[i] = -1;
      color[i] = 0;
    }

    int src = from - 1;
    int dst = to - 1;
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty())
    {
      src = q.front();
      q.pop();
      for (int i = 0; i < arrSize_; ++i)
      {
        if (arr_[src][i] != 0 && color[i] == 0)
        {
          color[i] = 1;
          dist[i] = dist[src] + 1;
          path[i] = src;
          q.push(i);
        }
      }
      color[src] = 2;
    }
    cout << "from " << from << " to " << to << " distance is " << dist[to-1] << endl;
  }

  void DFS(int from)
  {
    int color[arrSize_];
    int path[arrSize_];
    int dist[arrSize_];
    for (int i = 0; i < arrSize_; ++i)
    {
      color[i] = 0;
      path[i] = -1;
    }

    int src = from - 1;

  }

  void doDFS(int node, int *color, int *path)
  {
    color[node] = 1;
    path[node]
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

  int **arr_;
  int arrSize_;
};


class GraphAdjacentList{
 public:
};

#endif
