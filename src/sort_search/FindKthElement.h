#ifndef FIND_KTH_ELEMENT_H
#define FIND_KTH_ELEMENT_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <algorithm>

#include <testsuit/TestBase.h>

using namespace std;

class FindKthElement: public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================FindKthElement====================" << endl;
    vector<int> unsortArr = {7, 10, 4, 3, 20, 15};
    cout << "FindKthMinByHeapSort: " << FindKthMinByMinHeapSort(unsortArr, 3) << endl;
    cout << "FindKthMinByHeapSort: " << FindKthMinByMinHeapSort(unsortArr, 4) << endl;

    cout << "FindKthMinByHeapSort: " << FindKthMinByMaxHeap(unsortArr, 3) << endl;
    cout << "FindKthMinByHeapSort: " << FindKthMinByMaxHeap(unsortArr, 4) << endl;

    cout << "FindKthMinByQuickSelect: " << FindKthMinByQuickSelect(unsortArr, 3) << endl;
    cout << "FindKthMinByQuickSelect: " << FindKthMinByQuickSelect(unsortArr, 4) << endl;
    cout << "=================FindKthElement====================" << endl;
  }

  int FindKthMinByMinHeapSort(vector<int> unsortArr, int kth)
  {
    int length = unsortArr.size();
    for (int i = length / 2; i >= 0; --i)
    {
      minHeapDown(unsortArr, i, length);
    }

    for (int i = 0; i < kth - 1; ++i)
    {
      unsortArr[0] = unsortArr[--length];
      minHeapDown(unsortArr, 0, length);
    }

    return unsortArr[0];
  }

  int FindKthMinByMaxHeap(vector<int> unsortArr, int kth)
  {
    int length = kth;
    for (int i = length / 2; i >= 0; --i)
    {
      int curPos = i;
      maxHeapDown(unsortArr, curPos, length);
    }

    for (size_t i = kth; i < unsortArr.size(); ++i)
    {
      if (unsortArr[0] > unsortArr[i])
      {
        std::swap(unsortArr[0], unsortArr[i]);
        maxHeapDown(unsortArr, 0, length);
      }
    }

    return unsortArr[0];
  }

  int FindKthMinByQuickSelect(vector<int> unsortArr, int kth)
  {
    int value = quickSelect(unsortArr, 0, unsortArr.size() - 1, kth);

    return value;
  }


 private:
  int quickSelect(vector<int> &arr, int leftPos, int rightPos, int kth)
  {
    if (leftPos >= rightPos)
    {
      return arr[leftPos];
    }

    int leftIt = leftPos;
    int rightIt = rightPos - 1;
    while (leftIt <= rightIt)
    {
      if (arr[leftIt] < arr[rightPos])
      {
        ++leftIt;
        continue;
      }

      if (arr[rightIt] > arr[rightPos])
      {
        --rightIt;
        continue;
      }

      std::swap(arr[leftIt], arr[rightIt]);
    }

    std::swap(arr[leftIt], arr[rightPos]);
    if (leftIt == kth - 1)
    {
      return arr[leftIt];
    }
    else if(leftIt < kth -1)
    {
      return quickSelect(arr, leftIt + 1, rightPos, kth);
    }
    else
    {
      return quickSelect(arr, leftPos, leftIt - 1, kth);
    }
  }

  void showVector(const vector<int> &arr)
  {
    for (size_t i = 0; i < arr.size(); ++i)
    {
      cout << arr[i] << ",";
    }

    cout << endl;
  }
  void minHeapDown(vector<int> &unsortArr, int curPos, int length)
  {
    int holePos = curPos * 2 + 1;
    while (holePos <= length - 1)
    {
      if (holePos != length - 1 && unsortArr[holePos] > unsortArr[holePos + 1])
      {
        ++holePos;
      }

      if (unsortArr[curPos] > unsortArr[holePos])
      {
        std::swap(unsortArr[curPos], unsortArr[holePos]);
        curPos = holePos;
        holePos = curPos * 2 + 1;
      }
      else
      {
        break;
      }
    }
  }

  void maxHeapDown(vector<int> &unsortArr, int curPos, int length)
  {
    int holePos = curPos * 2 + 1;
    while (holePos <= length - 1)
    {
      if (holePos != length - 1 && unsortArr[holePos] < unsortArr[holePos + 1])
      {
        ++holePos;
      }

      if (unsortArr[curPos] < unsortArr[holePos])
      {
        std::swap(unsortArr[curPos], unsortArr[holePos]);
        curPos = holePos;
        holePos = curPos * 2 + 1;
      }
      else
      {
        break;
      }
    }
  }
};

#endif
