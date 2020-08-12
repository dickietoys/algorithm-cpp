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

class Node {
 public:
  int val;
  vector<Node*> neighbors;

  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }

  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }

  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  void RunTest()
  {
    int result = ReOrderCount({1, 7, 2, 9, 6, 4, 5, 3});
    cout << result << endl;
  }

  int count = 0;

  void Merge(vector<int> &arr, int left, int mid, int right)
  {
    vector<int> tmp(arr.size(), 0);

    int left_pos = left;
    int right_pos = mid + 1;
    int tmp_pos = left;
    while (left_pos <= mid && right_pos <= right)
    {
      if (arr[left_pos] > arr[right_pos])
      {
        count += mid - left_pos + 1;
        tmp[tmp_pos++] = arr[right_pos++];
      }
      else
      {
        tmp[tmp_pos++] = arr[left_pos++];
      }
    }

    while (left_pos <= mid)
    {
      tmp[tmp_pos++] = arr[left_pos++];
    }

    while (right_pos <= right)
    {
      tmp[tmp_pos++] = arr[right_pos++];
    }

    for (int i = left; i <= right; ++i)
    {
      arr[i] = tmp[i];
    }
  }

  void Aux(vector<int> &arr, int left, int right)
  {
    if (left >= right)
    {
      return;
    }
    int mid = left + (right - left) / 2;
    Aux(arr, left, mid);
    Aux(arr, mid + 1, right);
    Merge(arr, left, mid, right);
  }

  int ReOrderCount(vector<int> arr)
  {
    Aux(arr, 0, arr.size() - 1);
    return count;
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
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
        cout << result[i][j] << ", ";
      }
      cout << endl;
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();
  delete solution;
  return 0;
}
