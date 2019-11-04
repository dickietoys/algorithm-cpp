#ifndef FIND_LONGEST_PATH_H_
#define FIND_LONGEST_PATH_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include <testsuit/TestBase.h>

using namespace std;

// 1,2,3 steps
class FindLongestPath : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================FindLongestPath====================" << endl;
    vector<vector<int>> matrix(
        {
          {1, 2, 9},
          {5, 3, 8},
          {4, 6, 7}
        });
    cout << "BruteFind(): " << BruteFind(matrix) << endl;
    cout << "DpFind(): " << DpFind(matrix) << endl;
    cout << "=================FindLongestPath====================" << endl;
  }

  int BruteFind(vector<vector<int>> &matrix)
  {
    int max = 0;

    for (size_t i = 0; i < matrix.size(); ++i)
    {
      for (size_t j = 0; j < matrix[i].size(); ++j)
      {
        max = std::max(BruteFindAux(matrix, i, j, matrix[i][j] - 1), max);
      }
    }

    return max;
  }

  int DpFind(vector<vector<int>> &matrix)
  {
    vector<vector<int>> bookmark(matrix.size(), vector<int>(matrix[1].size(), -1));
    int max = 0;

    for (size_t i = 0; i < matrix.size(); ++i)
    {
      for (size_t j = 0; j < matrix[i].size(); ++j)
      {
        if (bookmark[i][j] == -1)
        {
          DpFindAux(matrix, i, j, matrix[i][j] - 1, bookmark);
        }
        max = std::max(bookmark[i][j], max);
      }
    }

    return max;
  }

 private:
  int BruteFindAux(vector<vector<int>> &matrix, int xpos, int ypos, int prevValue)
  {
    if (xpos < 0 || xpos >= static_cast<int>(matrix.size()))
    {
      return 0;
    }

    if (ypos < 0 || ypos >= static_cast<int>(matrix[xpos].size()))
    {
      return 0;
    }

    int curValue = matrix[xpos][ypos];
    if (curValue - prevValue != 1)
    {
      return 0;
    }
    int size1 = 1 + BruteFindAux(matrix, xpos + 1, ypos, curValue);
    int size2 = 1 + BruteFindAux(matrix, xpos - 1, ypos, curValue);
    int size3 = 1 + BruteFindAux(matrix, xpos, ypos + 1, curValue);
    int size4 = 1 + BruteFindAux(matrix, xpos, ypos - 1, curValue);

    return std::max({size1, size2, size3, size4});
  }

  int DpFindAux(vector<vector<int>> &matrix,
                int xpos,
                int ypos,
                int prevValue,
                vector<vector<int>> &bookmark)
  {
    if (xpos < 0 || xpos >= static_cast<int>(matrix.size()))
    {
      return 0;
    }

    if (ypos < 0 || ypos >= static_cast<int>(matrix[xpos].size()))
    {
      return 0;
    }

    if (bookmark[xpos][ypos] != -1)
    {
      return bookmark[xpos][ypos];
    }

    int curValue = matrix[xpos][ypos];
    if (curValue - prevValue != 1)
    {
      return 0;
    }
    int size1 = 1 + BruteFindAux(matrix, xpos + 1, ypos, curValue);
    int size2 = 1 + BruteFindAux(matrix, xpos - 1, ypos, curValue);
    int size3 = 1 + BruteFindAux(matrix, xpos, ypos + 1, curValue);
    int size4 = 1 + BruteFindAux(matrix, xpos, ypos - 1, curValue);

    bookmark[xpos][ypos] = std::max({size1, size2, size3, size4});
    return bookmark[xpos][ypos];
  }

  void showBookmark(vector<vector<int>> &bookmark)
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
