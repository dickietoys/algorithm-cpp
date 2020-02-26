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

    input = {2,5,6,0,0,1,2};
    result = search(input, 0);
    cout << "result: " << result << endl;
    assert(result == true);

    result = search(input, 3);
    cout << "result: " << result << endl;
    assert(result == false);
  }

  bool search(vector<int>& nums, int target) {
    if (nums.size() == 0)
    {
      return false;
    }

    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
      int middle = (left + right) / 2;
      if (nums[middle] == target)
      {
        return true;
      }

      if (nums[left] == nums[middle] && (nums[middle] == nums[right]))
      {
        ++left;
        --right;
      }
      else if (nums[left] <= nums[middle])
      {
        if (nums[left] <= target && target < nums[middle])
        {
          right = middle - 1;
        }
        else
        {
          left = middle + 1;
        }
      }
      else
      {
        if (nums[middle] < target && target <= nums[right])
        {
          left = middle + 1;
        }
        else
        {
          right = middle - 1;
        }
      }
    }

    return false;
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
