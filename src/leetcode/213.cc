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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  void RunTest()
  {
    vector<int> input = {2, 3, 2};
    int result = rob(input);

    cout << "result: " << result << endl;
  }

  int RobAux(vector<int>& nums, int start_pos, int last_pos)
  {
    int nums_size = nums.size();
    vector<int> dp(nums_size, 0);
    if (start_pos == 0)
    {
      dp[0] = nums[0];
      dp[1] = std::max(nums[0], nums[1]);
    }
    else
    {
      dp[1] = nums[1];
    }
    for (int i = start_pos; i <= last_pos; ++i)
    {
      dp[i] = std::max(dp[i-2] + nums[i], dp[i-1]);
    }

    return dp[last_pos];
  }

  int rob(vector<int>& nums) {
    int nums_size = nums.size();
    if (nums_size < 2)
    {
      return nums_size ? nums[0] : 0;
    }
    return std::max(RobAux(nums, 0, nums_size - 2), RobAux(nums, 1, nums_size - 1));
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
    }
    cout << endl;
  }

  template<class T>
  void Show(vector<vector<T>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ", ";
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
