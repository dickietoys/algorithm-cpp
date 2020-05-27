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

// Count Inversions
int GetInvCountMerge(vector<int> &arr, int left, int middle, int right)
{
  vector<int> buffer(arr.size(), 0);
  int left_pos = left;
  int right_pos = middle + 1;
  int buffer_pos = left;
  int counter = 0;
  while (left_pos <= middle && right_pos <= right)
  {
    if (arr[left_pos] <= arr[right_pos])
    {
      buffer[buffer_pos++] = arr[left_pos++];
    }
    else
    {
      counter += middle - left_pos + 1;
      buffer[buffer_pos++] = arr[right_pos++];
    }
  }

  while (left_pos <= middle)
  {
    buffer[buffer_pos++] = arr[left_pos++];
  }

  while (right_pos <= right)
  {
    buffer[buffer_pos++] = arr[right_pos++];
  }

  for (int i = left; i <= right; ++i)
  {
    arr[i] = buffer[i];
  }

  return counter;
}

int GetInvCountAux(vector<int> &arr, int left, int right)
{
  int counter = 0;
  if (left >= right)
  {
    return counter;
  }

  int middle = left + (right - left) / 2;
  counter += GetInvCountAux(arr, left, middle);
  counter += GetInvCountAux(arr, middle + 1, right);
  counter += GetInvCountMerge(arr, left, middle, right);

  return counter;
}

int GetInvCount(vector<int> arr)
{
  if (arr.empty())
  {
    return 0;
  }
  int counter = GetInvCountAux(arr, 0, arr.size() - 1);

  return counter;
}

//Maximum Subarray Sum

int MaxSubArraySumCrossAux(vector<int> &arr, int left, int middle, int right)
{
  int left_max = std::numeric_limits<int>::min();
  int pos = middle;
  int value = 0;
  while (pos >= left)
  {
    value += arr[pos--];
    left_max = std::max(value, left_max);
  }

  pos = middle + 1;
  value = 0;
  int right_max = std::numeric_limits<int>::min();
  while (pos <= right)
  {
    value += arr[pos++];
    right_max = std::max(value, right_max);
  }

  return left_max + right_max;
}

int MaxSubArraySumAux(vector<int> &arr, int left, int right)
{
  if (left >= right)
  {
    return arr[left];
  }

  int middle = left + (right - left) / 2;
  int left_max = MaxSubArraySumAux(arr, left, middle);
  int right_max = MaxSubArraySumAux(arr, middle + 1, right);
  int cross_max = MaxSubArraySumCrossAux(arr, left, middle, right);

  return std::max({left_max, cross_max, right_max});
}

int MaxSubArraySum(vector<int> arr)
{
  if (arr.empty())
  {
    return 0;
  }

  return MaxSubArraySumAux(arr, 0, arr.size() - 1);
}


//Longest Common Prefix

string LongestCommonPrefixAux(vector<string> &arr, int left, int right)
{
  if (left >= right)
  {
    return arr[left];
  }

  int middle = left + (right - left) / 2;
  string long_left = LongestCommonPrefixAux(arr, left, middle);
  string long_right = LongestCommonPrefixAux(arr, middle + 1, right);

  string buffer = "";
  int size = std::min(long_left.size(), long_right.size());
  for (int i = 0; i < size; ++i)
  {
    if (long_left[i] == long_right[i])
    {
      buffer += long_left[i];
    }
    else
    {
      break;
    }
  }
  return buffer;
}

string LongestCommonPrefix(vector<string> arr)
{
  if (arr.empty())
  {
    return "";
  }

  string result = LongestCommonPrefixAux(arr, 0, arr.size() - 1);

  return result;
}
