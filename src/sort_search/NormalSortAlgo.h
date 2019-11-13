#ifndef NORMAL_SORT_ALGO_H_
#define NORMAL_SORT_ALGO_H_

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <algorithm>

#include <testsuit/TestBase.h>

using namespace std;

class NormalSortAlgo: public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================NormalSortAlgo====================" << endl;
    vector<int> unsortArr = {5,2,1,9,8,7,3,4,6};
    cout << "---BubbleSort---" << endl;
    ShowVector(unsortArr);
    vector<int> sortArr = BubbleSort(unsortArr);
    ShowVector(sortArr);
    cout << "---SelectSort---" << endl;
    ShowVector(unsortArr);
    sortArr = SelectSort(unsortArr);
    ShowVector(sortArr);
    cout << "---InsertionSort---" << endl;
    ShowVector(unsortArr);
    sortArr = InsertionSort(unsortArr);
    ShowVector(sortArr);
    cout << "---MergeSort---" << endl;
    ShowVector(unsortArr);
    sortArr = MergeSort(unsortArr);
    ShowVector(sortArr);
    cout << "---HeapSort---" << endl;
    ShowVector(unsortArr);
    sortArr = HeapSort(unsortArr);
    ShowVector(sortArr);
    cout << "---QuickSort---" << endl;
    ShowVector(unsortArr);
    sortArr = QuickSort(unsortArr);
    ShowVector(sortArr);

    cout << "=================NormalSortAlgo====================" << endl;
  }

  vector<int> BubbleSort(vector<int> arr)
  {
    int length = arr.size();
    for (int i = 0; i < length; ++i)
    {
      for (int j = 0; j < length - i - 1; ++j)
      {
        if (arr[j] > arr[j+1])
        {
          std::swap(arr[j], arr[j+1]);
        }
      }
    }

    return arr;
  }

  vector<int> InsertionSort(vector<int> arr)
  {
    int length = arr.size();
    for (int i = 1; i < length; ++i)
    {
      int value = arr[i];
      int j = i - 1;
      while (j >= 0 && arr[j] > value)
      {
        arr[j+1] = arr[j];
        --j;
      }
      arr[j+1] = value;
    }

    return arr;
  }

  vector<int> SelectSort(vector<int> arr)
  {
    int length = arr.size();
    for (int i = 0; i < length - 1; ++i)
    {
      int minPos = i;
      for (int j = i + 1; j < length; ++j)
      {
        if (arr[minPos] > arr[j])
        {
          minPos = j;
        }
      }
      std::swap(arr[minPos], arr[i]);
    }

    return arr;
  }

  vector<int> MergeSort(vector<int> arr)
  {
    int leftPos = 0;
    int rightPos = arr.size() - 1;

    vector<int> buffer(arr.size(), 0);
    MergeSortAux(arr, buffer, leftPos, rightPos);

    return arr;
  }

  vector<int> QuickSort(vector<int> arr)
  {
    QuickSortAux(arr, 0, arr.size() - 1);
    return arr;
  }

  vector<int> HeapSort(vector<int> arr)
  {
    int length = arr.size();
    for (int i = length / 2; i >= 0; --i)
    {
      int curPos = i;
      int leftPos = curPos * 2 + 1;
      while (leftPos <= length - 1)
      {
        if (leftPos < length - 1 && arr[leftPos+1] < arr[leftPos])
        {
          ++leftPos;
        }

        if (arr[curPos] > arr[leftPos])
        {
          std::swap(arr[curPos], arr[leftPos]);
          curPos = leftPos;
          leftPos = curPos * 2 + 1;
        }
        else
        {
          break;
        }
      }
    }

    return arr;
  }


  vector<int> BucketSort(vector<int> arr)
  {
    return arr;
  }

  vector<int> RadixSort(vector<int> arr)
  {
    return arr;
  }

  vector<int> CountSort(vector<int> arr)
  {
    return arr;
  }

  void ShowVector(const vector<int> &arr)
  {
    for (auto it = arr.cbegin(); it != arr.cend(); ++it)
    {
      cout << *it << ", ";
    }
    cout << endl;
  }

 private:
  void MergeSortAux(vector<int> &arr, vector<int> &buffer, int leftPos, int rightPos)
  {
    if (leftPos < rightPos)
    {
      int midPos = (leftPos + rightPos) / 2;
      MergeSortAux(arr, buffer, leftPos, midPos);
      MergeSortAux(arr, buffer, midPos + 1, rightPos);

      int leftStartPos = leftPos;
      int rightStartPos = midPos + 1;
      int index = leftPos;
      while (leftStartPos <= midPos && rightStartPos <= rightPos)
      {
        if (arr[leftStartPos] > arr[rightStartPos] )
        {
          buffer[index++] = arr[rightStartPos++];
        }
        else
        {
          buffer[index++] = arr[leftStartPos++];
        }
      }

      while (leftStartPos <= midPos)
      {
        buffer[index++] = arr[leftStartPos++];
      }

      while (rightStartPos <= rightPos)
      {
        buffer[index++] = arr[rightStartPos++];
      }

      for (int i = leftPos; i <= rightPos; ++i)
      {
        arr[i] = buffer[i];
      }
    }
  }

  void QuickSortAux(vector<int> &arr, int leftPos, int rightPos)
  {
    if (leftPos >= rightPos)
    {
      return;
    }

    int i = leftPos;
    int j = rightPos - 1;
    int pivot = rightPos;
    while (i <= j)
    {
      if (arr[i] < arr[pivot])
      {
        ++i;
        continue;
      }

      if (arr[j] > arr[pivot])
      {
        --j;
        continue;
      }

      std::swap(arr[i], arr[j]);
    }

    std::swap(arr[i], arr[pivot]);
    QuickSortAux(arr, leftPos, i - 1);
    QuickSortAux(arr, i + 1, rightPos);
  }
};

#endif
