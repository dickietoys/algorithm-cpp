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
    int result;

    input = {1, 1, 1, 2, 2, 3};
    result = removeDuplicates(input);
    cout << "result: " << result << endl;
    assert(result == 5);
    Show(input);

    input = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    result = removeDuplicates(input);
    cout << "result: " << result << endl;
    assert(result == 7);
    Show(input);
  }

  int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
    if (size == 0)
    {
      return 0;
    }
    int i = 1;
    int index = 1;
    int value = nums[0];
    int counter = 1;
    while (i <= size - 1)
    {
      if (nums[i] == value)
      {
        ++counter;
        if (counter <= 2)
        {
          nums[index++] = nums[i];
        }
      }
      else
      {
        counter = 1;
        value = nums[i];
        nums[index++] = nums[i];
      }
      ++i;
    }

    return index;
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
