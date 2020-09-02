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

class Solution {
 public:
  void RunTest()
  {

  }

  int singleNumberWithSimple(vector<int>& nums)
  {
    vector<int> counter(32, 0);
    for (int i = 0; i < nums.size(); ++i)
    {
      int data = nums[i];
      for (int j = 0; j < 32; ++j)
      {
        int flag = 1;
        flag = flag << j;
        if (flag & data)
        {
          ++counter[j];
        }
      }
    }

    int result = 0;
    for (int i = 0; i < counter.size(); ++i)
    {
      result += (counter[i] % 3) << i;
    }

    return result;
  }

  int singleNumber(vector<int>& nums) {
    int ones = 0;
    int twos = 0;
    int common_mask = 0;
    int nums_size = nums.size();
    for (int i = 0; i < nums_size; ++i)
    {
      twos |= ones & nums[i];
      ones ^= nums[i];
      common_mask = ~(ones & twos);
      ones &= common_mask;
      twos &= common_mask;
    }

    return ones;
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
