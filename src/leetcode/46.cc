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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<int> input;
    vector<vector<int>> result;

    input = {1, 2, 3};
    result = permute(input);

  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    Aux(nums, 0, result);
    return result;
  }

  void Aux(vector<int>& nums, int pos, vector<vector<int>> &result)
  {
    if (pos == nums.size() - 1)
    {
      result.push_back(nums);
      return;
    }

    for (size_t i = pos; i < nums.size(); ++i)
    {
      std::swap(nums[pos], nums[i]);
      Aux(nums, pos + 1, result);
      std::swap(nums[pos], nums[i]);
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
