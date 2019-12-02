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
    bool result;

    input = {2, 3, 1, 1, 4};
    result = canJump(input);
    cout << "result: " << result << endl;

    input = {3, 2, 1, 0, 4};
    result = canJump(input);
    cout << "result: " << result << endl;
  }

  bool canJump(vector<int>& nums) {
    return Aux(nums, 0);
  }

  bool Aux(vector<int>& nums, int pos)
  {
    if (pos >= nums.size())
    {
      return false;
    }

    bool result = false;
    for (int i = 1; i <= nums[pos]; ++i)
    {
      result |= Aux(nums, pos + i);

      if (result)
      {
        return true;
      }
    }

    return false;
  }

  void Show(vector<int> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
