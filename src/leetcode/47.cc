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

    input = {3, 3, 0, 3};
    result = permuteUnique(input);
    Show(result);
  }

  void Aux(vector<int>& nums, int pos, vector<vector<int>> &result)
  {
    if (pos >= nums.size())
    {
      result.push_back(nums);
      return;
    }

    unordered_set<int> used;
    for (int i = pos; i < nums.size(); ++i)
    {
      if (used.count(nums[i]) == 1)
      {
        continue;
      }
      used.insert(nums[i]);
      std::swap(nums[i], nums[pos]);
      Aux(nums, pos + 1, result);
      std::swap(nums[i], nums[pos]);
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    Aux(nums, 0, result);
    return result;
  }

  void Show(vector<vector<int>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ",";
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
