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
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int result = search(nums, target);
    assert(result == 4);

    target = 3;
    result = search(nums, target);
    assert(result == -1);

    nums = {1};
    target = 0;
    result = search(nums, target);
    assert(result == -1);

    nums = {3, 1};
    target = 0;
    result = search(nums, target);
    assert(result == -1);
  }

  int binarySearch(vector<int>& nums, int left, int right, int target)
  {
    int leftPos = left;
    int rightPos = right;
    while (leftPos <= rightPos)
    {
      int middlePos = (leftPos + rightPos) / 2;
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

    return -1;
  }

  int search(vector<int>& nums, int target) {
    if (nums.size() == 0)
    {
      return -1;
    }

    int pivot = findPivot(nums);
    if (pivot == -1)
    {
      return binarySearch(nums, 0, nums.size() - 1, target);
    }

    if (nums[pivot] <= target && target <= nums[nums.size()-1])
    {
      return binarySearch(nums, pivot, nums.size() - 1, target);
    }
    else
    {
      return binarySearch(nums, 0, pivot - 1, target);
    }
  }

  int findPivot(vector<int>& nums)
  {
    if (nums[0] <= nums[nums.size() - 1])
    {
      return -1;
    }

    int left = 0;
    int right = nums.size() - 1;
    int leftPos = 0;
    int rightPos = nums.size() - 1;
    while (leftPos <= rightPos)
    {
      int middlePos = (leftPos + rightPos) / 2;
      if (middlePos == 0)
      {
        if (nums[middlePos] > nums[middlePos + 1])
        {
          return middlePos + 1;
        }
        else
        {
          return -1;
        }
      }
      else if (middlePos == right)
      {
        if (nums[middlePos] < nums[middlePos - 1])
        {
          return middlePos;
        }
        else
        {
          return - 1;
        }
      }


      if (nums[middlePos] < nums[middlePos - 1] && nums[middlePos] < nums[middlePos + 1])
      {
        return middlePos;
      }

      if (nums[middlePos] > nums[left])
      {
        //middle - right
        leftPos = middlePos + 1;
      }
      else
      {
        rightPos = middlePos - 1;
      }
    }

    return -1;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
