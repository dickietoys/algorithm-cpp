#ifndef KNAPSACK_PROBLEM_H_
#define KNAPSACK_PROBLEM_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include <testsuit/TestBase.h>

using namespace std;

typedef struct {
  int weight;
  int value;
}GoodsT;
/*
  0-1 背包问题，物品带价值，求最大价值
*/
class KnapsackProblem : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================KnapsackProblem====================" << endl;
    vector<GoodsT> arr = {{10, 60}, {20, 100}, {30, 120}};
    int knapsackSize = 50;
    cout << "BruteSelect: " << BruteSelect(arr, knapsackSize) << endl;
    cout << "DpSelect: " << DpSelect(arr, knapsackSize) << endl;

    arr = {{2, 3}, {2, 4}, {4, 8}, {6, 9}, {3, 6}};
    knapsackSize = 9;
    cout << "BruteSelect: " << BruteSelect(arr, knapsackSize) << endl;
    cout << "DpSelect: " << DpSelect(arr, knapsackSize) << endl;
    cout << "=================KnapsackProblem====================" << endl;
  }

  int BruteSelect(const vector<GoodsT> &arr, int knapsackSize)
  {
    return BruteSelectAux(arr, 0, knapsackSize, 0);
  }

  int DpSelect(const vector<GoodsT> &arr, int knapsackSize)
  {
    return DpSelectAux(arr, knapsackSize);
  }

 private:
  int BruteSelectAux(const vector<GoodsT> &arr, int pos, int knapsackSize, int currentSize)
  {
    if (static_cast<int>(arr.size()) == pos)
    {
      return 0;
    }

    int value1 = 0;
    int value2 = 0;
    if (currentSize + arr[pos].weight <= knapsackSize)
    {
      value1 = arr[pos].value + BruteSelectAux(arr, pos + 1, knapsackSize, currentSize + arr[pos].weight);
    }

    value2 = BruteSelectAux(arr, pos + 1, knapsackSize, currentSize);

    return std::max(value1, value2);
  }

  int DpSelectAux(const vector<GoodsT> &arr, int knapsackSize)
  {
    int xLen = knapsackSize + 1;
    int yLen = arr.size() + 1;
    vector<vector<int>> bookmark(yLen, vector<int>(xLen, 0));
    for (int i = 1; i < yLen; ++i)
    {
      for (int j = 1; j < xLen; ++j)
      {
        if (arr[i-1].weight <= j)
        {
          bookmark[i][j] = std::max(arr[i-1].value + bookmark[i-1][j-arr[i-1].weight],
                                    bookmark[i-1][j]);
        }
        else
        {
          bookmark[i][j] = bookmark[i-1][j];
        }
      }
    }

    return bookmark[arr.size()][knapsackSize];
  }

  void showBookmark(const vector<vector<int>> &bookmark)
  {
    cout << endl;
    for (size_t i = 0; i < bookmark.size(); ++i)
    {
      for (size_t j = 0; j < bookmark[i].size(); ++j)
      {
        cout << bookmark[i][j] << ", ";
      }
      cout << endl;
    }
  }
};

/*
  0-1 背包问题，忽略物品价值，求最大携带量
*/
class KnapsackIgnoreGoodsValueProblem : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================KnapsackIgnoreGoodsValueProblem====================" << endl;
    vector<GoodsT> arr = {{10, 60}, {20, 100}, {30, 120}};
    int knapsackSize = 50;
    cout << "BruteSelect: " << BruteSelect(arr, knapsackSize) << endl;
    cout << "DpSelect: " << DpSelect(arr, knapsackSize) << endl;

    arr = {{2, 3}, {2, 4}, {4, 8}, {6, 9}, {3, 6}};
    knapsackSize = 9;
    cout << "BruteSelect: " << BruteSelect(arr, knapsackSize) << endl;
    cout << "DpSelect: " << DpSelect(arr, knapsackSize) << endl;
    cout << "=================KnapsackIgnoreGoodsValueProblem====================" << endl;
  }

  int BruteSelect(const vector<GoodsT> &arr, int knapsackSize)
  {
    return BruteSelectAux(arr, 0, knapsackSize, 0);
  }

  int DpSelect(const vector<GoodsT> &arr, int knapsackSize)
  {
    return DpSelectAux(arr, knapsackSize);
  }

 private:
  int BruteSelectAux(const vector<GoodsT> &arr, int pos, int knapsackSize, int currentSize)
  {
    if (static_cast<int>(arr.size()) == pos)
    {
      return currentSize;
    }

    int size1 = 0;
    int size2 = 0;
    if (arr[pos].weight + currentSize <= knapsackSize)
    {
      size1 = BruteSelectAux(arr, pos + 1, knapsackSize, arr[pos].weight + currentSize);
    }

    size2 = BruteSelectAux(arr, pos + 1, knapsackSize, currentSize);

    return std::max(size1, size2);
  }

  int DpSelectAux(const vector<GoodsT> &arr, int knapsackSize)
  {
    vector<vector<int>> bookmark(arr.size() + 1, vector<int>(knapsackSize + 1, 0));
    for (size_t i = 0; i < bookmark.size(); ++i)
    {
      bookmark[i][0] = 1;
    }

    for (size_t i = 1; i <= arr.size(); ++i)
    {
      for (int j = 1; j <= knapsackSize; ++j)
      {
        bookmark[i][j] = bookmark[i-1][j];
        if (j - arr[i-1].weight >= 0)
        {
          bookmark[i][j] |= bookmark[i-1][j - arr[i-1].weight];
        }
      }
    }

    for (int i = knapsackSize; i >= 0; --i)
    {
      if (bookmark[arr.size()][i] == 1)
      {
        return i;
      }
    }

    return 0;
  }

  void showBookmark(const vector<vector<int>> &bookmark)
  {
    cout << endl;
    for (size_t i = 0; i < bookmark.size(); ++i)
    {
      for (size_t j = 0; j < bookmark[i].size(); ++j)
      {
        cout << bookmark[i][j] << ", ";
      }
      cout << endl;
    }
  }
};

#endif
