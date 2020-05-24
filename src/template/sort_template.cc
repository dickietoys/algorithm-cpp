#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <iterator>
#include <set>
#include <cmath>
#include <queue>

using namespace std;

vector<int> SelectionSort(vector<int> arr)
{
  if (arr.empty())
  {
    return arr;
  }

  for (int i = 0; i < arr.size() - 1; ++i)
  {
    int min_pos = i;
    for (int j = i + 1; j < arr.size(); ++j)
    {
      if (arr[j] < arr[min_pos])
      {
        min_pos = j;
      }
    }
    std::swap(arr[min_pos], arr[i]);
  }

  return arr;
}

vector<int> BubbleSort(vector<int> arr)
{
  if (arr.empty())
  {
    return arr;
  }

  for (int i = 0; i < arr.size(); ++i)
  {
    for (int j = 0; j < arr.size() - i - 1; ++j)
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
  if (arr.empty())
  {
    return arr;
  }

  for (int i = 1; i < arr.size(); ++i)
  {
    int value = arr[i];
    int j = i - 1;
    for (; j >= 0; --j)
    {
      if (value < arr[j])
      {
        arr[j] = arr[j-1];
      }
    }
  }

  return arr;
}

vector<int> MergeSort(vector<int> arr)
{
  return arr;
}

vector<int> QuickSort(vector<int> arr)
{
  return arr;
}

vector<int> HeapSort(vector<int> arr)
{
  return arr;
}

vector<int> CountingSort(vector<int> arr)
{
  return arr;
}

vector<int> RadixSort(vector<int> arr)
{
  return arr;
}

vector<int> BucketSort(vector<int> arr)
{
  return arr;
}
