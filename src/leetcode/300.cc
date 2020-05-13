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
#include <queue>

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
  }

  int lengthOfLIS(vector<int>& nums) {
    int nums_size = nums.size();
    if (nums_size <= 0)
    {
      return 0;
    }

    vector<int> dp(nums_size, 0);
    dp[0] = 1;
    int max = 1;
    for (int i = 1; i < nums_size; ++i)
    {
      int cur_max = 0;
      for (int j = 0; j < i; ++j)
      {
        if (nums[i] > nums[j])
        {
          cur_max = std::max(cur_max, dp[j]);
        }
      }
      dp[i] = cur_max + 1;
      max = std::max(dp[i], max);
    }

    return max;
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
