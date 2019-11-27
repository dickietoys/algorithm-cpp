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
    vector<int> input = {1,2,3};
    nextPermutation(input);
    Show(input);
  }

  void nextPermutation(vector<int>& nums) {
    Aux(nums, nums.size()-1);
  }

  void Aux(vector<int>& nums, int pos)
  {
    if (pos == 0)
    {
      int i = 0;
      int j = nums.size() - 1;
      while (i < j)
      {
        std::swap(nums[i], nums[j]);
        ++i;
        --j;
      }

      return;
    }

    if (nums[pos-1] < nums[pos])
    {
      std::swap(nums[pos-1], nums[pos]);
    }
    else
    {
      Aux(nums, pos - 1);
    }
  }

  void Show(vector<int> result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
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
