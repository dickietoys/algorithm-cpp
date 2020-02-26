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
#include <sstream>
#include <iterator>
#include <set>
#include <cmath>

using namespace std;

class Solution {
 public:
  void RunTest()
  {

  }

  int singleNumber(vector<int>& nums) {
    int ones = 0;
    int twos = 0;
    int common_mask = 0;
    int nums_size = nums.size();
    for (int i = 0; i < nums_size; ++i)
    {
      twos |= ones & nums[i];
      ones ^= nums[i];
      common_mask = ~(ones & twos);
      ones &= common_mask;
      twos &= common_mask;
    }

    return ones;
  }

  void Show(vector<int> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
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
