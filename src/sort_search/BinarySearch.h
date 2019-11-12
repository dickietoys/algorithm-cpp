#ifndef BINARY_SEARCH_H_
#define BINARY_SEARCH_H_

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <algorithm>

#include <testsuit/TestBase.h>

using namespace std;

class BinarySearch: public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================BinarySearch====================" << endl;
    vector<int> sortedArr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << FindSorted(sortedArr, 10) << endl;
    cout << FindSorted(sortedArr, 5) << endl;
    cout << FindSorted(sortedArr, 2) << endl;
    cout << FindSorted(sortedArr, 7) << endl;


    cout << "rotated" << endl;
    sortedArr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    cout << FindSortedAndRotated(sortedArr, 10) << endl;
    cout << FindSortedAndRotated(sortedArr, 5) << endl;
    cout << FindSortedAndRotated(sortedArr, 2) << endl;
    cout << FindSortedAndRotated(sortedArr, 7) << endl;
    cout << "=================BinarySearch====================" << endl;
  }

  bool FindSorted(const vector<int> &sortedArr, int value)
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

  bool FindSortedAndRotated(const vector<int> &sortedArr, int value)
  {
    int pivot = FindPivot(sortedArr);
    if (pivot == -1)
    {
      FindSorted(sortedArr, value);
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
