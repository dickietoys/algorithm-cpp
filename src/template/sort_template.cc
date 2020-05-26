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
    while (j >= 0 && value < arr[j])
    {
      arr[j+1] = arr[j];
      --j;
    }
    arr[j+1] = value;
  }

  return arr;
}

void MergeSortConquer(vector<int> &arr, int left_pos, int middle_pos, int right_pos)
{
  vector<int> buffer(arr.size(), 0);

  int buffer_index = left_pos;
  int left_start = left_pos;
  int right_start = middle_pos + 1;
  while (left_start <= middle_pos && right_start <= right_pos)
  {
    if (arr[left_start] < arr[right_start])
    {
      buffer[buffer_index++] = arr[left_start++];
      continue;
    }
    else
    {
      buffer[buffer_index++] = arr[right_start++];
      continue;
    }
  }

  while (left_start <= middle_pos)
  {
    buffer[buffer_index++] = arr[left_start++];
  }

  while (right_start <= right_pos)
  {
    buffer[buffer_index++] = arr[right_start++];
  }

  for (int i = left_pos; i <= right_pos; ++i)
  {
    arr[i] = buffer[i];
  }
}

void MergeSortDivideConquer(vector<int> &arr, int left_pos, int right_pos)
{
  if (left_pos >= right_pos)
  {
    return;
  }

  int middle_pos = left_pos + (right_pos - left_pos) / 2;
  MergeSortDivideConquer(arr, left_pos, middle_pos);
  MergeSortDivideConquer(arr, middle_pos + 1, right_pos);
  MergeSortConquer(arr, left_pos, middle_pos, right_pos);
}

vector<int> MergeSort(vector<int> arr)
{
  if (arr.empty())
  {
    return arr;
  }

  MergeSortDivideConquer(arr, 0, arr.size() - 1);

  return arr;
}

int QuickSortRecursivePivot(vector<int> &arr, int left, int right)
{
  int pivot_value = arr[right];
  int left_start = left;
  for (int i = left; i <= right - 1; ++i)
  {
    if (arr[i] < pivot_value)
    {
      std::swap(arr[left_start++], arr[i]);
    }
  }
  std::swap(arr[left_start], arr[right]);
  return left_start;
}

void QuickSortRecursive(vector<int> &arr, int left, int right)
{
  if (left >= right)
  {
    return;
  }

  int pivot = QuickSortRecursivePivot(arr, 0, right);
  QuickSortRecursive(arr, left, pivot - 1);
  QuickSortRecursive(arr, pivot + 1, right);
}

vector<int> QuickSort(vector<int> arr)
{
  if (arr.empty())
  {
    return arr;
  }

  QuickSortRecursive(arr, 0, arr.size() - 1);

  return arr;
}

vector<int> HeapSort(vector<int> arr)
{
  std::priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
  vector<int> result;
  while (!pq.empty())
  {
    result.push_back(pq.top());
    pq.pop();
  }
  return result;
}

vector<int> CountingSort(vector<int> arr)
{
  if (arr.empty())
  {
    return arr;
  }

  int max = *std::max_element(arr.begin(), arr.end());
  int min = *std::min_element(arr.begin(), arr.end());
  int count_size = max - min + 1;
  vector<int> counter(count_size, 0);
  for (int v : arr)
  {
    counter[v-min]++;
  }

  for (int i = 1; i < counter.size(); ++i)
  {
    counter[i] += counter[i - 1];
  }

  vector<int> output(arr.size(), 0);
  for (int i = 0; i < arr.size(); ++i)
  {
    output[counter[arr[i] - min] - 1] = arr[i];
    --counter[arr[i] - min];
  }

  return output;
}


void CountingSortAux(vector<int> &arr, int exp)
{
  if (arr.empty())
  {
    return;
  }

  vector<int> counter(10, 0);
  for (int v : arr)
  {
    counter[v / exp % 10]++;
  }

  for (int i = 1; i < counter.size(); ++i)
  {
    counter[i] += counter[i - 1];
  }

  vector<int> output(arr.size(), 0);
  for (int i = arr.size() - 1; i >= 0; --i)
  {
    output[counter[arr[i] / exp % 10] - 1] = arr[i];
    --counter[arr[i] / exp % 10];
  }

  for (int i = 0; i < arr.size(); ++i)
  {
    arr[i] = output[i];
  }
}

vector<int> RadixSort(vector<int> arr)
{
  if (arr.empty())
  {
    return arr;
  }
  int max = *std::max_element(arr.begin(), arr.end());
  for (int i = 1; max / i > 0; i *= 10)
  {
    CountingSortAux(arr, i);
  }
  return arr;
}

vector<int> BucketSort(vector<int> arr)
{
  return arr;
}
