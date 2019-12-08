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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<int> input;
    vector<vector<int>> result;

    input = {1, 2, 3};
    result = subsets(input);
    Show(result);
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result = {{}};
    vector<int> buffer;
    Aux(nums, result, 0, buffer);
    return result;
  }

  void Aux(vector<int> &nums, vector<vector<int>> &result, int pos, vector<int> &buffer)
  {
    if (pos >= nums.size())
    {
      return;
    }

    for (int i = pos; i < nums.size(); ++i)
    {
      buffer.push_back(nums[i]);
      result.push_back(buffer);
      Aux(nums, result, i+1, buffer);
      buffer.pop_back();
    }
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
