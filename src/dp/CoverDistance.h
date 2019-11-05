#ifndef COVER_DISTANCE_H_
#define COVER_DISTANCE_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include <testsuit/TestBase.h>

using namespace std;

/*
  给定距离n，每次可以走1\2\3距离,共有多少走法
*/
class CoverDistance : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================CoverDistance====================" << endl;
    int distance = 3;
    printf("BruteCount(%d) : %d\n", distance, BruteCount(distance));
    printf("DpCount(%d) : %d\n", distance, DpCount(distance));

    distance = 4;
    printf("BruteCount(%d) : %d\n", distance, BruteCount(distance));
    printf("DpCount(%d) : %d\n", distance, DpCount(distance));
    cout << "=================CoverDistance====================" << endl;
  }

  int BruteCount(int n)
  {
    return BruteCountAux(n);
  }

  int DpCount(int n)
  {
    return DpCountAux(n);
  }

 private:
  int BruteCountAux(int n)
  {
    if (n == 0)
    {
      return 1;
    }

    if (n < 0)
    {
      return 0;
    }

    return BruteCountAux(n - 1) + BruteCountAux(n - 2) + BruteCountAux(n - 3);
  }


  int DpCountAux(int n)
  {
    vector<int> bookmark(n+1, 0);
    bookmark[0] = 1;
    bookmark[1] = 1;
    bookmark[2] = 2;
    for (int i = 3; i <= n; ++i)
    {
      bookmark[i] = bookmark[i - 1] + bookmark[i - 2] + bookmark[i - 3];
    }

    return bookmark[n];
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
