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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<int> input;
    vector<int> result;

    input = {2, 5, 6};
    result = {1, 2, 3, 0, 0, 0};
    merge(result, 3, input, 3);
    Show(result);

    input = {1, 2, 3};
    result = {4, 5, 6, 0, 0, 0};
    merge(result, 3, input, 3);
    Show(result);
  }

  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int index = m + n - 1;
    while (m > 0 && n > 0)
    {
      if (nums1[m-1] >= nums2[n-1])
      {
        nums1[index--] = nums1[m-1];
        --m;
      }
      else
      {
        nums1[index--] = nums2[n-1];
        --n;
      }
    }

    while (n > 0)
    {
      nums1[index--] = nums2[n-1];
      --n;
    }

    while (m > 0)
    {
      nums1[index--] = nums1[m-1];
      --m;
    }
  }

  void Show(vector<int> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
  }

  void Show(vector<vector<int>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ",";
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
