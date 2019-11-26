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

    arr = {-1, 0, 1, 2, -1, -4};
    result = threeSum(arr);
    Show(result);
  }

  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    std::sort(nums.begin(), nums.end());
    int length = nums.size();
    for (int i = 0; i < length; ++i)
    {
      int j = i + 1;
      int k = length - 1;
      if (i != 0 && nums[i] == nums[i-1])
      {
        continue;
      }
      while (j < k)
      {
        if (nums[i] + nums[j] + nums[k] == 0)
        {
          result.push_back({nums[i], nums[j], nums[k]});
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
