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
    vector<int> input = {1, 3, 4, 2, 2};
    int result = findDuplicate(input);
    cout << result << endl;
  }

  int findDuplicate(vector<int>& nums) {
    int nums_size = nums.size();
    if (nums_size <= 1)
    {
      return 0;
    }

    int left = 0;
    int right = nums_size - 1;
    while (left < right)
    {
      int mid = left + (right - left) / 2;
      int count = 0;
      for (int v : nums)
      {
        if (v <= mid)
        {
          ++count;
        }
      }
      if (count <= mid)
      {
        left = mid;
      }
      else
      {
        right = mid - 1;
      }
    }

    return left;
  }

  int findDup2(vector<int> &nums)
  {
    if (nums.size() > 1)
    {
      int slow = nums[0];
      int fast = nums[nums[0]];
      while (slow != fast)
      {
        slow = nums[slow];
        fast = nums[nums[fast]];
      }

      fast = 0;
      while (fast != slow)
      {
        fast = nums[fast];
        slow = nums[slow];
      }
      return slow;
    }
    return -1;
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
