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
  }

  int minSubArrayLen(int s, vector<int>& nums) {
    int nums_size = nums.size();
    if (nums_size == 0)
    {
      return 0;
    }
    int left_pos = 0;
    int right_pos = 0;
    int sum = 0;
    int min_len = std::numeric_limits<int>::max();
    while (right_pos < nums_size)
    {
      sum += nums[right_pos];
      while (sum >= s)
      {
        int len = right_pos - left_pos + 1;
        min_len = std::min(len, min_len);
        sum -= nums[left_pos];
        ++left_pos;
      }
      ++right_pos;
    }

    return min_len == std::numeric_limits<int>::max() ? 0 : min_len;
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
