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
#include <functional>
#include <list>
#include <exception>

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
    double result = findMedianSortedArrays({1,3}, {2});
    cout << "{1,3}, {2}; result: " << result << endl;
    result = findMedianSortedArrays({1,2}, {3,4});
    cout << "{1,2}, {3,4}; result: " << result << endl;
    result = findMedianSortedArrays({0,0}, {0,0});
    cout << "{0,0}, {0,0}; result: " << result << endl;
    result = findMedianSortedArrays({}, {1});
    cout << "{}, {1}; result: " << result << endl;
    result = findMedianSortedArrays({2}, {});
    cout << "{2}, {}; result: " << result << endl;

  }

  /*
    [1 2]
    [3 4]

    [1] [2]
    [3] [4]

    [1][2] []
    []     [3 4]

    [1] [2,3]

    [2 3 4] []
  */
  double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
    if (nums1.size() > nums2.size())
    {
      std::swap(nums1, nums2);
    }

    int left1_size = 0;
    int left2_size = 0;
    int total_size = nums1.size() + nums2.size();
    int left_pos = 0;
    int right_pos = nums1.size();
    while (left_pos <= right_pos)
    {
      left1_size = left_pos + (right_pos - left_pos) / 2;
      left2_size = (total_size + 1) / 2 - left1_size;
      if (left1_size > 0 && left2_size < nums2.size() && nums1[left1_size - 1] > nums2[left2_size])
      {
        right_pos = left1_size - 1;
      }
      else if (left2_size > 0 && left1_size < nums1.size() && nums2[left2_size - 1] > nums1[left1_size])
      {
        left_pos = left1_size + 1;
      }
      else
      {

      }
    }

    return 0;
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
