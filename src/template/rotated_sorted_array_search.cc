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
    cout << "pivot: " << pivot << endl;
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

    int nums_size = nums.size();
    int left = 0;
    int right = nums_size - 1;
    while (left < right)
    {
      if (nums[left] < nums[right])
      {
        return left;
      }
      int mid = (left + right) / 2;
      if (nums[left] <= nums[mid])
      {
        left = mid + 1;
      }
      else
      {
        right = mid;
      }
    }

    return left;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
