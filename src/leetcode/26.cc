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
    vector<int> inputs = {1, 1, 2};
    int result = removeDuplicates(inputs);
    cout << "result: " << result << endl;
    assert(result == 2);

    inputs = {0,0,1,1,1,2,2,3,3,4};
    result = removeDuplicates(inputs);
    cout << "result: " << result << endl;
    assert(result == 5);

  }

  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0)
    {
      return 0;
    }

    int validPos = 0;
    for (int i = 1; i < nums.size(); ++i)
    {
      if (nums[validPos] == nums[i])
      {
        continue;
      }
      else
      {
        std::swap(nums[++validPos], nums[i]);
      }
    }

    return validPos + 1;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
