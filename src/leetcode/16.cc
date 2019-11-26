#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    vector<int> arr;
    int target;
    int result;

    arr = {-1, 2, 1, -4};
    target = 1;
    result = threeSumClosest(arr, target);
    cout << "result: " << result << endl;
    assert(result == 2);
  }

  int threeSumClosest(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int length = nums.size();
    int diff = std::numeric_limits<int>::max();
    int closestSum = 0;
    for (int i = 0; i < length; ++i)
    {
      int j = i + 1;
      int k = length - 1;
      while (j < k)
      {
        int sum = nums[i] + nums[j] + nums[k];
        if (diff > std::abs(sum - target))
        {
          diff = std::abs(sum - target);
          closestSum = sum;
        }

        if (sum > target)
        {
          --k;
        }
        else if (sum < target)
        {
          ++j;
        }
        else
        {
          return closestSum;
        }
      }
    }

    return closestSum;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
