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
  }

  int maxProduct(vector<int>& nums) {
    int nums_size = nums.size();
    int max = std::numeric_limits<int>::min();
    int pos_start = -1;
    int pos_stop = -1;
    for (int i = 0; i < nums_size; ++i)
    {
      int cur_max = nums[i];
      if (cur_max > max)
      {
        max = cur_max;
        pos_start = i;
        pos_stop = i;
      }
      for (int j = i + 1; j < nums_size; ++j)
      {
        cur_max *= nums[j];
        if (cur_max > max)
        {
          max = cur_max;
          pos_start = i;
          pos_stop = j;
        }
      }
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
