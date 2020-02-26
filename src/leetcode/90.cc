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
#include <bitset>

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<int> input;
    vector<vector<int>> result;

    result = subsetsWithDup(input);
    Show(result);
  }

  vector<vector<int>> subsetsWithDup(vector<int>& nums)
  {
    vector<vector<int>> result = {{}};
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size();)
    {
      int count = 0;
      while (count + i < nums.size() && nums[count + i] == nums[i])
      {
        ++count;
      }

      int resultSize = result.size();
      for (int j = 0; j < resultSize; ++j)
      {
        vector<int> prevResult = result[j];
        for (int k = 0; k < count; ++k)
        {
          prevResult.push_back(nums[i]);
          result.push_back(prevResult);
        }
      }

      i += count;
    }

    return result;
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
