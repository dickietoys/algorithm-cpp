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

class Solution {
 public:
  void RunTest()
  {
    cout << (5 & 6 & 7) << endl;
    // vector<int> input = {1, 2, 3, 1};
    // int result = rob(input);
    // cout << result << endl;
  }

  int rob(vector<int>& nums)
  {
    int nums_size = nums.size();
    vector<int> notebook(nums_size, 0);
    if (nums_size == 0)
    {
      return 0;
    }

    if (nums_size == 1)
    {
      return nums[0];
    }

    notebook[0] = nums[0];
    notebook[1] = std::max(nums[0], nums[1]);
    for (int i = 2; i < nums_size; ++i)
    {
      notebook[i] = std::max(notebook[i-1], notebook[i-2] + nums[i]);
    }

    return notebook[nums_size-1];
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
