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

    // input = {-2,1,-3,4,-1,2,1,-5,4};
    // result = maxSubArray(input);
    // cout << "result: " << result << endl;

    input = {-1, -2};
    result = maxSubArray(input);
    cout << "result: " << result << endl;
  }

  // int maxSubArray(vector<int>& nums) {
  //   int size = nums.size();
  //   int max = nums[0];
  //   int curSum = nums[0];
  //   for (int i = 1; i < size; ++i)
  //   {
  //     curSum = std::max(curSum + nums[i], nums[i]);
  //     max = std::max(max, curSum);
  //   }

  //   return max;
  // }

  int maxSubArray(vector<int>& nums) {
    int size = nums.size();
    int max = nums[0];
    int curSum = nums[0];
    for (int i = 1; i < size; ++i)
    {
      curSum = std::max(curSum + nums[i], nums[i]);
      max = std::max(max, curSum);
    }

    return max;
  }

  int Aux(vector<int>& nums, int leftPos, int rightPos)
  {
    if (leftPos == rightPos)
    {
      return nums[leftPos];
    }

    int middlePos = (leftPos + rightPos) / 2;
    int leftSum = Aux(nums, leftPos, middlePos);
    int rightSum = Aux(nums, middlePos + 1, rightPos);
    int crossLeftSum = 0;
    int crossLeftMax = 0;
    int crossStartPos = 0;
    for (int i = middlePos; i>= leftPos; --i)
    {
      crossLeftSum += nums[i];
      if (crossLeftSum >= crossLeftMax)
      {
        crossLeftMax = crossLeftSum;
        crossStartPos = middlePos;
      }
    }
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
