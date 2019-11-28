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
    vector<int> input = {1, 3, 2};
    Show(input);
    nextPermutation(input);
    Show(input);
  }

  void nextPermutation(vector<int>& nums) {
    int length = nums.size();
    int i = length - 2;

    while (i >= 0 && nums[i] >= nums[i+1])
    {
      --i;
    }

    int j = length - 1;
    if (i >= 0)
    {
      while (j >= 0 && nums[j] <= nums[i])
      {
        --j;
      }
      std::swap(nums[i], nums[j]);
    }

    int k = length - 1;
    j = i + 1;
    while (j < k)
    {
      std::swap(nums[k], nums[j]);
      ++j;
      --k;
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
