#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <algorithm>

#include <testsuit/TestBase.h>

using namespace std;

class GraphMatrix
{
 public:
  GraphMatrix(int nodeSize) :
      graphData_(vector<vector<int>>(nodeSize, vector<int>(nodeSize, 0)))
  {}

  void AddEdge(int from, int to)
  {
    graphData_[from][to] = 1;
  }

 private:
  vector<vector<int>> graphData_;
};

class GraphList
{
 public:
  GraphList(int nodeSize) :
      graphData_(vector<list<int>>(nodeSize, list<int>()))
  {}

  void AddEdge(int from, int to)
  {
    list<int> &item = graphData_[from];
    if (find(item.cbegin(), item.cend(), to) == item.cend())
    {
      item.push_back(to);
    }
  }

  void ShowGraph()
  {
    cout << "---------ShowGraph Start---------" << endl;
    for (size_t i = 0; i < graphData_.size(); ++i)
    {
      cout << i << ", ";
      for (list<int>::const_iterator it = graphData_[i].cbegin(); it != graphData_[i].cend(); ++it)
      {
        cout << *it << ", ";
      }
      cout << endl;
    }
    cout << "---------ShowGraph End---------" << endl;
  }

  void BFS(int from)
  {
    queue<int> nodeQueue;
    map<int, bool> bookmark;
    for (size_t i = 0; i < graphData_.size(); ++i)
    {
      bookmark.insert({i, false});
    }
    nodeQueue.push(from);
    bookmark[from] = true;
    while (!nodeQueue.empty())
    {
      int node = nodeQueue.front();
      nodeQueue.pop();
      cout << node << ", ";
      const list<int> &item = graphData_[node];
      for (list<int>::const_iterator it = item.cbegin(); it != item.cend(); ++it)
      {
        if (bookmark[*it] == false)
        {
          nodeQueue.push(*it);
          bookmark[*it] = true;
        }
      }
    }

    cout << endl;
  }

  void DFS(int from)
  {
    map<int, bool> bookmark;
    for (size_t i = 0; i < graphData_.size(); ++i)
    {
      bookmark.insert({i, false});
    }

    DFSAux(from, bookmark);
    cout << endl;
  }

 private:
  void DFSAux(int from, map<int, bool> &bookmark)
  {
    cout << from << ", ";
    bookmark[from] = true;
    list<int> &item = graphData_[from];
    for (list<int>::const_iterator it = item.cbegin(); it != item.cend(); ++it)
    {
      if (!bookmark[*it])
      {
        DFSAux(*it, bookmark);
      }
    }
  }

 private:
  vector<list<int>> graphData_;
};


class GraphTest: public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================GraphTest====================" << endl;
    GraphList graphList(4);
    graphList.AddEdge(0, 1);
    graphList.AddEdge(0, 2);
    graphList.AddEdge(1, 2);
    graphList.AddEdge(2, 0);
    graphList.AddEdge(2, 3);
    graphList.AddEdge(3, 3);
    graphList.ShowGraph();
    graphList.BFS(2);
    graphList.DFS(2);
    cout << "=================GraphTest====================" << endl;
  }
};

#endif
