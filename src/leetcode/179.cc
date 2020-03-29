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
    cout << std::pow(10, 2) << endl;
  }

  string largestNumber(vector<int>& nums) {
    vector<string> str_nums;
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
      str_nums.push_back(std::to_string(*it));
    }
    std::sort(str_nums.begin(), str_nums.end(), [](string &s1, string &s2)
              {
                int s1_size = s1.size();
                int s2_size = s2.size();
                int s_size = std::min(s1.size(), s2.size());
                for (int i = 0; i < s_size; ++i)
                {
                  if (s1[i] != s2[i])
                  {
                    return s1[i] > s2[i] ? true : false;
                  }
                }
                if (s1_size == s2_size)
                {
                  return true;
                }

                if (s1_size < s2_size)
                {
                  for (int i = s1_size; i < s2_size; ++i)
                  {
                    if ()
                  }
                }
              });
    string result = "";
    for (auto it = str_nums.begin(); it != str_nums.end(); ++it)
    {
      result += *it;
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
