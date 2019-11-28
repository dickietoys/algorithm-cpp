#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>
#include <deque>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    string input = "(()";
    int result = longestValidParentheses(input);
    cout << "result: " << result << endl;
    assert(result == 2);

    input = ")()())";
    result = longestValidParentheses(input);
    cout << "result: " << result << endl;
    assert(result == 4);

    input = "()(()";
    result = longestValidParentheses(input);
    cout << "result: " << result << endl;
    assert(result == 2);
  }

  bool isValid(string s)
  {
    stack<int> st;
    for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] == '(')
      {
        st.push(1);
      }
      else
      {
        if (st.empty())
        {
          return false;
        }
        else
        {
          st.pop();
        }
      }
    }

    return st.empty();
  }

  int longestValidParentheses(string s) {

    int max = 0;
    for (int i = 2 ; i <= s.size(); i += 2)
    {
      for (int j = 0; j <= s.size() - i; ++j)
      {
        if (isValid(s.substr(j, i)))
        {
          max = std::max(i, max);
        }
      }
    }

    return max;
  }

  // int longestValidParentheses(string s) {
  //   int max = 0;
  //   for (int i = 2 ; i <= s.size(); i += 2)
  //   {
  //     for (int j = 0; j <= s.size() - i; ++j)
  //     {
  //       if (isValid(s.substr(j, i)))
  //       {
  //         max = std::max(i, max);
  //       }
  //     }
  //   }

  //   return max;
  // }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
