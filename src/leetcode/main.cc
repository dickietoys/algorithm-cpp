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
    vector<int> input = {0, 0, 0, 0, 0, 0};
    string result = largestNumber(input);
    cout << result << endl;
  }

  string largestNumber(vector<int>& nums) {
    if (nums.size() == 0)
    {
      return "";
    }

    if (nums.size() == 1)
    {
      return std::to_string(nums[0]);
    }
    vector<string> str_nums;
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
      str_nums.push_back(std::to_string(*it));
    }
    std::sort(str_nums.begin(), str_nums.end(),
              [](string &lhs, string &rhs) -> bool
              {
                return lhs + rhs >= rhs + lhs ? true : false;
              });
    stringstream ss;
    for (auto it = str_nums.begin(); it != str_nums.end(); ++it)
    {
      ss << *it;
    }

    string result = ss.str();
    if (result[0] == '0')
    {
      result = "0";
    }

    return result;
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
