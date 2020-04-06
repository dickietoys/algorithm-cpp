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
    vector<int> input = {1, 2, 3, 1};
    int result = rob(input);
    cout << result << endl;
  }

  int rob(vector<int>& nums)
  {
    int nums_size = nums.size();
    if (nums_size < 0)
    {
      return 0;
    }
    return Aux(nums, nums_size - 1);
  }

  int Aux(vector<int>& nums, int pos)
  {
    if (pos < nums.size())
    {
      return 0;
    }

    return std::max(nums[pos] + Aux(nums, pos - 2), Aux(nums, pos - 1));
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
