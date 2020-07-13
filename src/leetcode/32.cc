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

  /*
    If s[i] is '(', set longest[i] to 0,because any string end with '(' cannot be a valid one.

    Else if s[i] is ')'

    If s[i-1] is '(', longest[i] = longest[i-2] + 2

    Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]

    For example, input "()(())", at i = 5, longest array is [0,2,0,0,2,0], longest[5] = longest[4] + 2 + longest[1] = 6.
  */

  int longestValidParentheses(string s)
  {
    if(s.length() <= 1)
    {
      return 0;
    }

    int curMax = 0;
    vector<int> dp(s.size(),0);
    for(int i=1; i < s.length(); i++)
    {
      if(s[i] == ')')
      {
        if(s[i-1] == '(')
        {
          dp[i] = (i-2) >= 0 ? (dp[i-2] + 2) : 2;
          curMax = max(dp[i],curMax);
        }
        else{ // if s[i-1] == ')', combine the previous length.
          if(i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(')
          {
            dp[i] = dp[i-1] + 2 + ((i-dp[i-1]-2 >= 0) ? dp[i-dp[i-1]-2] : 0);
            curMax = max(dp[i],curMax);
          }
        }
      }
    }
    return curMax;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
