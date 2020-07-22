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

  void Aux(vector<int>& nums, int pos, vector<int> &item, vector<vector<int>> &result)
  {
    result.push_back(item);

    for (int i = pos; i < nums.size(); ++i)
    {
      if (i > pos && nums[i] == nums[i - 1])
      {
        continue;
      }

      item.push_back(nums[i]);
      Aux(nums, i + 1, item, result);
      item.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int>& nums)
  {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> item;
    Aux(nums, 0, item, result);
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
