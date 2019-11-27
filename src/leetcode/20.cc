#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    string input;
    bool output;
  }

  bool isValid(string s) {
    stack<char> st;
    for (size_t i = 0; i < s.size(); ++i)
    {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{')
      {
        st.push(s[i]);
      }
      else
      {
        if (st.empty())
        {
          return false;
        }
        if (s[i] == ')')
        {
          if (st.top() == '(')
          {
            st.pop();
          }
          else
          {
            return false;
          }
        }
        else if (s[i] == ']')
        {
          if (st.top() == '[')
          {
            st.pop();
          }
          else
          {
            return false;
          }
        }
        else if (s[i] == '}')
        {
          if (st.top() == '{')
          {
            st.pop();
          }
          else
          {
            return false;
          }
        }
      }
    }

    if (st.empty())
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
