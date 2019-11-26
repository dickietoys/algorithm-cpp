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
    vector<vector<int>> result;
    int target;

    arr = {-1, 0, 1, 2, -1, -4};
    target = 0;
    result = fourSum(arr, target);
    Show(result);
  }

  vector<vector<int>> fourSum(vector<int>& nums, int target)
  {
    vector<vector<int>> result;
    std::sort(nums.begin(), nums.end());
    int length = nums.size();
    for (int i = 0; i < length; ++i)
    {
      if (i != 0 && nums[i] == nums[i-1])
      {
        continue;
      }
      for (int n = i+1; n < length; ++n)
      {
        if (i != i+1 && nums[i] == nums[i-1])
        {
          continue;
        }

        int j = n + 1;
        int k = length - 1;
        while (j < k)
        {
          if (nums[i] + nums[n] + nums[j] + nums[k] == target)
          {
            result.push_back({nums[i], nums[n], nums[j], nums[k]});
            while (j < k && nums[j+1] == nums[j])
            {
              ++j;
            }

            while (j < k && nums[k-1] == nums[k])
            {
              --k;
            }

            ++j;
            --k;
          }
          else if (nums[i] + nums[j] + nums[k] > 0)
          {
            --k;
          }
          else
          {
            ++j;
          }
        }
      }
    }

    return result;
  }

  void Show(vector<vector<int>> &result)
  {
    for (auto it = result.begin(); it != result.end(); ++it)
    {
      for (auto iit = it->begin(); iit != it->end(); ++iit)
      {
        cout << *iit << ", ";
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
