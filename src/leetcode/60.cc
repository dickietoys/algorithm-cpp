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
    int input;
    string result;

    result = getPermutation(3, 3);
    cout << "result: " << result << endl;
    assert(result == "213");

    result = getPermutation(4, 9);
    cout << "result: " << result << endl;
    assert(result == "2314");
  }

  string getPermutation(int n, int k) {
    string result;
    vector<int> nums;
    int totalCount = 1;
    for (int i = 1; i <= n; ++i)
    {
      totalCount *= i;
      nums.push_back(i);
    }

    int eachCount = 0;
    int index = 0;
    int remain = 0;
    k = k - 1;
    for (int i = 0; i < n; ++i)
    {
      eachCount = totalCount / (n - i);
      index = k / eachCount;
      remain = k % eachCount;
      result.append(std::to_string(nums[index]));
      nums.erase(std::find(nums.begin(), nums.end(), nums[index]));
      totalCount = eachCount;
      k = remain;
    }

    cout << result << endl;

    return result;
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
