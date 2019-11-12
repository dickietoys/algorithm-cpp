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
    vector<int> sortArr = BubbleSort(unsortArr);
    ShowVector(sortArr);
    cout << "---SelectSort---" << endl;
    sortArr = SelectSort(unsortArr);
    ShowVector(sortArr);
    cout << "---InsertionSort---" << endl;
    sortArr = InsertionSort(unsortArr);
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
    return arr;
  }

  vector<int> HeapSort(vector<int> arr)
  {
    return arr;
  }

  vector<int> QuickSort(vector<int> arr)
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
};

#endif
