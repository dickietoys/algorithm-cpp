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

  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    int nums_size = nums.size();
    if (nums_size <= 0)
    {
      return result;
    }
    int left = 0;
    int right = 0;
    nums.push_back(nums[nums_size-1] - 1);
    ++nums_size;
    for (right = 0; right < nums_size; ++right)
    {
      if ((long)nums[right] - (long)nums[left] == right - left && right != nums_size - 1)
      {
        continue;
      }
      else
      {
        if (right - left <= 1)
        {
          result.push_back(std::to_string(nums[left]));
        }
        else
        {
          result.push_back(std::to_string(nums[left]) + "->" + std::to_string(nums[right-1]));
        }
        left = right;
      }
    }

    return result;
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
