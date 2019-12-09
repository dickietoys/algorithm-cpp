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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<int> input;
    vector<int> result;

    input = {1, 2, 3};
    Show(input);
    result = plusOne(input);
    Show(result);

    input = {4, 3, 2, 1};
    Show(input);
    result = plusOne(input);
    Show(result);
  }

  vector<int> plusOne(vector<int>& digits) {
    int remain = 1;
    int value = 0;
    vector<int>::reverse_iterator it;
    for (it = digits.rbegin(); it != digits.rend(); ++it)
    {
      value = *it + remain;
      remain = value / 10;
      value = value % 10;
      *it = value;
    }

    if (remain)
    {
      digits.insert(digits.begin(), remain);
    }

    return digits;
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
