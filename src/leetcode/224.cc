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
    stack<int> st;
    long sum = 0;
    long number = 0;
    int sign = 1;
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
      else if (s[i] == '+')
      {
        sum += sign * number;
        number = 0;
        sign = 1;
      }
      else if (s[i] == '-')
      {
        sum += sign * number;
        number = 0;
        sign = -1;
      }
      else if (s[i] == '(')
      {
        st.push(sum);
        st.push(sign);
        number = 0;
        sign = 1;
        sum = 0;
      }
      else if (s[i] == ')')
      {
        sum += sign * number;
        int prev_sign = st.top();
        st.pop();
        int prev_sum = st.top();
        st.pop();
        sum *= prev_sign;
        sum = prev_sum + sum;
        number = 0;
      }
    }

    if (number != 0)
    {
      sum += sign * number;
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
