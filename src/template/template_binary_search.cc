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


// 普通二叉搜索
int BinarySearchNormal(vector<int> arr, int target)
{
  if (arr.empty())
  {
    return -1;
  }
  int left = 0;
  int right = arr.size() - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }

    if (arr[mid] > target)
    {
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }

  return -1;
}

// rotate旋转数组的支点
int FindPivot(vector<int> arr)
{
  if (arr.empty())
  {
    return -1;
  }
  int low = 0;
  int high = arr.size() - 1;
  while (low < high)
  {
    if (arr[low] == arr[high])
    {
      ++low;
      continue;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] > arr[high])
    {
      low = mid + 1;
    }
    else
    {
      high = mid;
    }
  }

  return low;
}


// 查找第一个值等于给定值的元素
int FindFirstEqual(vector<int> arr, int target)
{
  if (arr.empty())
  {
    return -1;
  }
  int left = 0;
  int right = arr.size() - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
    {
      if (mid == 0 || arr[mid-1] != target)
      {
        return mid;
      }
      else
      {
        right = mid - 1;
      }
    }
    else if (arr[mid] > target)
    {
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }

  return -1;
};

// 查找最后一个值等于给定值的元素
int FindLastEqual(vector<int> arr, int target)
{
  if (arr.empty())
  {
    return -1;
  }
  int left = 0;
  int right = arr.size() - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
    {
      if (mid == arr.size() - 1 || arr[mid+1] != target)
      {
        return mid;
      }
      else
      {
        left = mid + 1;
      }
    }
    else if (arr[mid] > target)
    {
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }

  return -1;
};

// 第一个不小于指定值的元素
int FindLowerBound(vector<int> arr, int target)
{
  if (arr.empty())
  {
    return -1;
  }
  int left = 0;
  int right = arr.size() - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      if (mid == 0 || arr[mid-1] < target)
      {
        return mid;
      }
      else
      {
        right = mid - 1;
      }
    }
  }

  return -1;
};

// 最后一个小于等于给定值的元素
int FindLastLessEq(vector<int> arr, int target)
{
  if (arr.empty())
  {
    return -1;
  }
  int left = 0;
  int right = arr.size() - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] > target)
    {
      right = mid - 1;
    }
    else
    {
      if (mid == arr.size() - 1 || arr[mid+1] > target)
      {
        return mid;
      }
      else
      {
        left = mid + 1;
      }
    }
  }

  return -1;
};
