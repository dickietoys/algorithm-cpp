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

  int findMin(vector<int>& nums) {
    int nums_size = nums.size();
    if (nums_size == 0)
    {
      return 0;
    }

    int start_pos = 0;
    int end_pos = nums_size - 1;
    while (start_pos < end_pos)
    {
      if (nums[start_pos] < nums[end_pos])
      {
        return nums[start_pos];
      }

      int mid = (start_pos + end_pos) / 2;
      if (nums[mid] >= nums[start_pos])
      {
        start_pos = mid + 1;
      }
      else
      {
        end_pos = mid;
      }
    }

    return nums[start_pos];
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
