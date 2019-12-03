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
    int size = nums.size();
    int lastPos = size - 1;
    for (int i = size - 2; i >= 0; --i)
    {
      if (nums[i] + i >= lastPos)
      {
        lastPos = i;
      }
    }

    return lastPos == 0;
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
