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
    bool result;

    input = {1};
    sortColors(input);
    Show(input);
  }

  void sortColors(vector<int>& nums) {
    int size = nums.size();
    vector<int> counter(3, 0);

    for (int i = 0; i < size; ++i)
    {
      ++counter[nums[i]];
    }

    for (int i = 0; i < counter[0]; ++i)
    {
      nums[i] = 0;
    }

    for (int i = 0; i < counter[1]; ++i)
    {
      nums[i+counter[0]] = 1;
    }
    for (int i = 0; i < counter[2]; ++i)
    {
      nums[i+counter[0]+counter[1]] = 2;
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
