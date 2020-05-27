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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  void RunTest()
  {
    vector<string> arr = {"geeksforgeeks", "geeks", "geek", "geezer"};
    string result = LongestCommonPrefix(arr);
    cout << result << endl;
  }

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

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", " << endl;
    }
    cout << endl;
  }

  template<class T>
  void Show(vector<vector<T>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ", " << endl;
      }
      cout << endl;
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
