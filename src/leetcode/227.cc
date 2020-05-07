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
    string s = "123";
    int result = calculate(s);
    cout << result << endl;
  }

  bool is_number(char c)
  {
    if (c >= '0' && c <= '9')
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  int calculate(string s) {
    char sign = '+';
    long number = 0;
    stack<int> st;
    s += "+";
    for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] == ' ')
      {
        continue;
      }

      if (is_number(s[i]))
      {
        number = number * 10 + s[i] - '0';
      }
      else if (sign == '+')
      {
        st.push(number);
        number = 0;
        sign = s[i];
      }
      else if (sign == '-')
      {
        st.push(-number);
        number = 0;
        sign = s[i];
      }
      else if (sign == '*')
      {
        int value = st.top() * number;
        st.pop();
        st.push(value);
        sign = s[i];
        number = 0;
      }
      else if (sign == '/')
      {
        int value = st.top() / number;
        st.pop();
        st.push(value);
        sign = s[i];
        number = 0;
      }
    }

    int sum = 0;
    while (!st.empty())
    {
      sum += st.top();
      st.pop();
    }

    return sum;
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
