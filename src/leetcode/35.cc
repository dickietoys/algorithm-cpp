#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>
#include <deque>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    vector<int> nums = {};
    int target = 0;
    int result = 0;

    nums = {1, 3, 5, 6};
    target = 5;
    result = searchInsert(nums, target);
    assert(result == 2);

    target = 2;
    result = searchInsert(nums, target);
    assert(result == 1);

    target = 7;
    result = searchInsert(nums, target);
    assert(result == 4);

    target = 0;
    result = searchInsert(nums, target);
    assert(result == 0);

    nums = {1, 3};
    target = 2;
    result = searchInsert(nums, target);
    assert(result == 1);
  }

  void show(vector<int>& nums)
  {
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
      cout << *it << ", ";
    }

    cout << endl;
  }

  int searchInsert(vector<int>& nums, int target) {
    if (nums.empty())
    {
      return 1;
    }

    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target)
      {
        return mid;
      }
      else if (nums[mid] > target)
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }

    return left > right ? left : right;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
