#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    vector<int> arr = {};
    int result = 0;

    arr = {1,8,6,2,5,4,8,3,7};
    result = maxArea(arr);
    cout << "result: " << result << endl;
    assert(result == 49);
  }

  int maxArea(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int max = 0;
    int curMax = 0;
    while (i < j)
    {
      curMax = (j - i) * std::min(height[j], height[i]);
      max = std::max(max, curMax);
      if (height[j] > height[i])
      {
        ++i;
      }
      else
      {
        --j;
      }
    }

    return max;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
