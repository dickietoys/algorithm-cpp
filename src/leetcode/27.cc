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
    vector<int> inputs = {3, 2, 2, 3};
    int result = removeElement(inputs, 3);
    cout << "result: " << result << endl;
    assert(result == 2);

    inputs = {0,1,2,2,3,0,4,2};
    result = removeElement(inputs, 2);
    cout << "result: " << result << endl;
    assert(result == 5);
  }

  int removeElement(vector<int>& nums, int val) {
    if (nums.size() == 0)
    {
      return 0;
    }

    if (nums.size() == 1)
    {
      if (nums[0] == val)
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }

    int endPos = nums.size() - 1;
    for (int i = 0; i <= endPos;)
    {
      if (val == nums[i])
      {
        std::swap(nums[endPos--], nums[i]);
      }
      else
      {
        ++i;
      }
    }

    return endPos + 1;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
