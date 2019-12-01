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
#include <unordered_map>

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<int> input;
    int result;

    input = {-2,1,-3,4,-1,2,1,-5,4};
    result = maxSubArray(input);
    cout << "result: " << result << endl;
  }

  int maxSubArray(vector<int>& nums) {
    return aux(nums, 0, 0);
  }

  int aux(vector<int>& nums, int pos, int sum)
  {
    if (pos == nums.size())
    {
      return sum;
    }

    int length = nums.size();
    int max = 0;
    for (int i = pos; i < length; ++i)
    {
      max = std::max({max,
            aux(nums, pos + 1, sum + nums[i]),
            aux(nums, pos + 1, sum)});
    }

    return max;
  }

  void Show(vector<vector<string>> &result)
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
