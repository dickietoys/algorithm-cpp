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
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> result = searchRange(nums, target);
    show(result);

    nums = {5,7,7,8,8,10};
    target = 6;
    result = searchRange(nums, target);
    show(result);
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

  vector<int> searchRange(vector<int>& nums, int target) {
    int pos = binarySearch(nums, 0, nums.size() - 1, target);
    int first = pos;
    int end = pos;

    while (first > 0 && nums[first - 1] == target)
    {
      --first;
    }

    while (end < nums.size() - 1 && nums[end + 1] == target)
    {
      ++end;
    }

    vector<int> result;
    result.push_back(first);
    result.push_back(end);

    return result;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
