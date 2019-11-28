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

  int binarySearch(vector<int>& nums, int left, int right, int target)
  {
    int leftPos = left;
    int rightPos = right;
    int middlePos = left;
    while (leftPos <= rightPos)
    {
      middlePos = (leftPos + rightPos) / 2;
      if (nums[middlePos] == target)
      {
        return middlePos;
      }
      else if (nums[middlePos] > target)
      {
        rightPos = middlePos - 1;
      }
      else
      {
        leftPos = middlePos + 1;
      }
    }

    return middlePos;
  }

  int searchInsert(vector<int>& nums, int target) {
    int pos = binarySearch(nums, 0, nums.size() - 1, target);
    cout << "pos: " << pos << endl;
    if (target == nums[pos])
    {
      return pos;
    }

    if (nums[pos] > target)
    {
      return pos;
    }
    else
    {
      return ++pos;
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
