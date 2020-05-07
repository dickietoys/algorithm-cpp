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
  }

  vector<int> majorityElement(vector<int>& nums) {
    vector<int> result;
    int nums_size = nums.size();
    if (nums_size <= 0)
    {
      return result;
    }

    int nums1 = 0;
    int count1 = 0;
    int nums2 = 0;
    int count2 = 0;

    for (int i = 0; i < nums_size; ++i)
    {
      if (nums1 == nums[i])
      {
        ++count1;
      }
      else if (nums2 == nums[i])
      {
        ++count2;
      }
      else if (count1 == 0)
      {
        nums1 = nums[i];
        count1 = 1;
      }
      else if (count2 == 0)
      {
        nums2 = nums[i];
        count2 = 1;
      }
      else
      {
        --count1;
        --count2;
      }
    }

    count1 = 0;
    count2 = 0;
    for (int i = 0; i < nums_size; ++i)
    {
      if (nums[i] == nums1)
      {
        ++count1;
      }
      else if (nums[i] == nums2)
      {
        ++count2;
      }
    }

    if (count1 > nums_size / 3)
    {
      result.push_back(nums1);
    }

    if (count2 > nums_size / 3)
    {
      result.push_back(nums2);
    }

    return result;
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

  return 0;
}
