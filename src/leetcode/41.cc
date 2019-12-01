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
    int result;
    int target;

    input = {1,2,0};
    result = firstMissingPositive(input);
    cout << "result: " << result << endl;
  }

  int firstMissingPositive(vector<int>& nums)
  {
    int i = 0;
    int j = 1;
    int min = std::min(nums[i], nums[j]);
    int max = std::max(nums[i], nums[j]);

    while (j < nums.size())
    {
      min = std::min(min, nums[j]);
      max = std::max(max, nums[j]);
      if (max - min != j - i)
      {
        return j;
      }
      else
      {
        ++j;
      }
    }

    return -1;
  }

};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
