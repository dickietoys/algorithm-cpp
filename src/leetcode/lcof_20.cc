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
#include <queue>
#include <functional>
#include <list>
#include <exception>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  void RunTest()
  {
    string s = ".0..";
    bool result = isNumber(s);
    cout << "result: " << result << endl;
  }
  /*
    请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。
  */

  bool hasUnsignedNumber(string &s)
  {
    int i = 0;
    while (i < s.size())
    {
      if (s[i] >= '0' && s[i] <= '9')
      {
        ++i;
      }
      else
      {
        break;
      }
    }

    if (i == 0)
    {
      return false;
    }
    else
    {
      s = s.substr(i);
      return true;
    }
  }

  bool hasSignedNumber(string &s)
  {
    if (s.empty())
    {
      return false;
    }
    int pos = s.find_first_not_of(' ');
    s = s.substr(pos);
    if (s.empty())
    {
      return false;
    }
    pos = s.find_last_not_of(' ');
    s = s.substr(0, pos+1);
    if (s[0] == '+' || s[0] == '-')
    {
      s = s.substr(1);
    }

    return hasUnsignedNumber(s);
  }

  bool isNumber(string s) {
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
    bool is_number = hasSignedNumber(s);
    if (s[0] == '.')
    {
      s = s.substr(1);
      is_number = hasUnsignedNumber(s) || is_number;
    }

    if (!is_number)
    {
      return false;
    }

    if (s[0] == 'e' || s[0] == 'E')
    {
      s = s.substr(1);
      is_number = hasSignedNumber(s);
    }

    return is_number && s.empty();
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
  delete solution;
  return 0;
}
