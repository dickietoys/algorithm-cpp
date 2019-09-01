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

  void BFS(int src, int dst)
  {
    int dist[arrSize_];
    int path[arrSize_];
    int color[arrSize_];
    for (int i = 0; i < arrSize_; ++i)
    {
      dist[i] = -1;
      path[i] = -1;
    }

    src = src - 1;
    dst = dst - 1;
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty())
    {
      src = q.front();
      q.pop();
      for (int i = 0; i < arrSize_; ++i)
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
      color[ids] = 2;
    }

    for (int i = 0; i < arrSize_; ++i)
    {
      cout << "dist[" << i << "] : " << dist[i] << ", " << endl;
    }

    for (int i = 0; i < arrSize_; ++i)
    {
      cout << "color[" << i << "] : " << color[i] << ", " << en]dl;
    }


    cout << "from " << src << " to " << dst << " distance is " << dist[dst] << endl;
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
