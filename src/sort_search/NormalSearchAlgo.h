#ifndef NORMAL_SEARCH_ALGO_H_
#define NORMAL_SEARCH_ALGO_H_

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <algorithm>

#include <testsuit/TestBase.h>

using namespace std;

class NormalSearchAlgo: public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================NormalSearchAlgo====================" << endl;
    vector<int> sortedArr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << BinarySearch(sortedArr, 10) << endl;
    cout << BinarySearch(sortedArr, 5) << endl;
    cout << BinarySearch(sortedArr, 2) << endl;
    cout << BinarySearch(sortedArr, 7) << endl;


    cout << "rotated" << endl;
    sortedArr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    cout << BinarySearchAndRotated(sortedArr, 10) << endl;
    cout << BinarySearchAndRotated(sortedArr, 5) << endl;
    cout << BinarySearchAndRotated(sortedArr, 2) << endl;
    cout << BinarySearchAndRotated(sortedArr, 7) << endl;
    cout << "=================NormalSearchAlgo====================" << endl;
  }

  bool BinarySearch(const vector<int> &sortedArr, int value)
  {
    int startPos = 0;
    int endPos = sortedArr.size() - 1;
    while (startPos <= endPos)
    {
      int middlePos = (startPos + endPos) / 2;
      if (value == sortedArr[middlePos])
      {
        return true;
      }

      if (value > sortedArr[middlePos])
      {
        startPos = middlePos + 1;
      }
      else
      {
        endPos = middlePos - 1;
      }
    }

    return false;
  }

  bool BinarySearchAndRotated(const vector<int> &sortedArr, int value)
  {
    int pivot = FindPivot(sortedArr);
    if (pivot == -1)
    {
      BinarySearch(sortedArr, value);
    }
    else
    {
      int leftPos = 0;
      int rightPos = 0;
      if (value >= sortedArr[0])
      {
        leftPos = 0;
        rightPos = pivot - 1;
      }
      else
      {
        leftPos = pivot;
        rightPos = sortedArr.size() - 1;
      }

      while (leftPos <= rightPos)
      {
        int middlePos = (leftPos + rightPos) / 2;
        if (value == sortedArr[middlePos])
        {
          return true;
        }

        if (value > sortedArr[middlePos])
        {
          leftPos = middlePos + 1;
        }
        else
        {
          rightPos = middlePos - 1;
        }
      }
    }

    return false;
  }

  int FindPivot(const vector<int> &sortedArr)
  {
    int leftPos = 0;
    int rightPos = sortedArr.size() - 1;
    if (sortedArr[rightPos] > sortedArr[leftPos])
    {
       return -1;
    }

    while (leftPos <= rightPos)
    {
      int middlePos = (leftPos + rightPos) / 2;
      if (sortedArr[middlePos] > sortedArr[middlePos+1])
      {
        return middlePos+1;
      }

      if (sortedArr[middlePos-1] > sortedArr[middlePos])
      {
        return middlePos;
      }

      if (sortedArr[middlePos] > sortedArr[rightPos])
      {
        leftPos = middlePos + 1;
      }
      else if (sortedArr[middlePos] < sortedArr[leftPos])
      {
        rightPos = middlePos - 1;
      }
    }

    return -1;
  }
};

#endif
