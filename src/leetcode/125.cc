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
#include <bitset>

using namespace std;

class Solution {
 public:

  void RunTest()
  {
    bool result = isPalindrome("race a car");
    cout << "result: " << result << endl;
  }

  bool isPalindrome(string s) {
    if (s.size() == 0)
    {
      return true;
    }
    int i = 0;
    int j = s.size() - 1;
    while (i <= j)
    {
      cout << i << ":" << j << endl;
      if (!isAlpha(s[i]))
      {
        ++i;
        continue;
      }

      if (!isAlpha(s[j]))
      {
        --j;
        continue;
      }

      if (std::tolower(s[i]) == std::tolower(s[j]))
      {
        ++i;
        --j;
      }
      else
      {
        return false;
      }
    }

    return true;
  }

  bool isAlpha(char c)
  {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
      return true;
    }

    return false;
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
