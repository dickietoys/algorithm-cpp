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
    numSquares(10);
  }

  int numSquares(int n) {
    vector<int> dp(n + 1, std::numeric_limits<int>::max());
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
      for (int j = 1; j * j <= i; ++j)
      {
        cout << dp[i - j * j] + 1 << endl;
        dp[i] = std::min(dp[i], dp[i - j * j] + 1);
        cout << dp[i] << endl;
      }
    }

    return dp.back();
  }

  int findDup2(vector<int> &nums)
  {
    if (nums.size() > 1)
    {
      int slow = nums[0];
      int fast = nums[nums[0]];
      while (slow != fast)
      {
        slow = nums[slow];
        fast = nums[nums[fast]];
      }

      fast = 0;
      while (fast != slow)
      {
        fast = nums[fast];
        slow = nums[slow];
      }
      return slow;
    }
    return -1;
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
