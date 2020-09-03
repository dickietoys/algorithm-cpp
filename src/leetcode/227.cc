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
    int result = calculateWith2Stack("2*3+4");
    cout << "result: " << result << endl;
  }


  int calculateWith2Stack(string s)
  {
    stack<long> st_num;
    stack<char> st_op;
    long num = 0;
    bool has_num = false;
    for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] == ' ')
      {
        continue;
      }

      if (s[i] >= '0' && s[i] <= '9')
      {
        num = num * 10 + s[i] - '0';
        has_num = true;
      }
      else
      {
        if (has_num)
        {
          st_num.push(num);
          num = 0;
          has_num = false;
        }

        if (s[i] == '+' || s[i] == '-')
        {
          while (!st_op.empty() && st_op.top() != '(')
          {
            int data2 = st_num.top();
            st_num.pop();
            int data1 = st_num.top();
            st_num.pop();
            if (st_op.top() == '+')
            {
              st_num.push(data1 + data2);
            }
            else if (st_op.top() == '-')
            {
              st_num.push(data1 - data2);
            }
            else if (st_op.top() == '*')
            {
              st_num.push(data1 * data2);
            }
            else if (st_op.top() == '/')
            {
              st_num.push(data1 / data2);
            }
            st_op.pop();
          }
          st_op.push(s[i]);
        }
        else if (s[i] == '*' || s[i] == '/')
        {
          while (!st_op.empty()
                 && st_op.top() != '('
                 && st_op.top() != '+'
                 && st_op.top() != '-')
          {
            int data2 = st_num.top();
            st_num.pop();
            int data1 = st_num.top();
            st_num.pop();
            if (st_op.top() == '*')
            {
              st_num.push(data1 * data2);
            }
            else if (st_op.top() == '/')
            {
              st_num.push(data1 / data2);
            }
            st_op.pop();
          }
          st_op.push(s[i]);
        }
        else if (s[i] == '(')
        {
          st_op.push(s[i]);
        }
        else if (s[i] == ')')
        {
          while (!st_op.empty() && st_op.top() != '(')
          {
            int data2 = st_num.top();
            st_num.pop();
            int data1 = st_num.top();
            st_num.pop();

            if (st_op.top() == '*')
            {
              st_num.push(data1 * data2);
            }
            else if (st_op.top() == '/')
            {
              st_num.push(data1 / data2);
            }
            else if (st_op.top() == '+')
            {
              st_num.push(data1 + data2);
            }
            else if (st_op.top() == '-')
            {
              st_num.push(data1 - data2);
            }
            st_op.pop();
          }
          st_op.pop();
        }
      }
    }

    if (has_num)
    {
      st_num.push(num);
    }

    while (!st_op.empty())
    {
      int data2 = st_num.top();
      st_num.pop();
      int data1 = st_num.top();
      st_num.pop();
      if (st_op.top() == '*')
      {
        st_num.push(data1 * data2);
      }
      else if (st_op.top() == '/')
      {
        st_num.push(data1 / data2);
      }
      else if (st_op.top() == '+')
      {
        st_num.push(data1 + data2);
      }
      else if (st_op.top() == '-')
      {
        st_num.push(data1 - data2);
      }
      st_op.pop();
    }

    return st_num.top();
  }

  vector<string> In2Post(string &s)
  {
    vector<string> post_eval;
    stack<char> st;
    string result;
    for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] == ' ')
      {
        continue;
      }

      if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z'))
      {
        result += s[i];
      }
      else
      {
        if (!result.empty())
        {
          post_eval.push_back(result);
          result.clear();
        }

        if (s[i] == '(')
        {
          st.push(s[i]);
        }
        else if (s[i] == ')')
        {
          while (!st.empty() && st.top() != '(')
          {
            post_eval.push_back(string() + st.top());
            st.pop();
          }
          st.pop();
        }
        else
        {
          if (s[i] == '+' || s[i] == '-')
          {
            while (!st.empty() && st.top() != '(')
            {
              post_eval.push_back(string() + st.top());
              st.pop();
            }
            st.push(s[i]);
          }
          else if (s[i] == '*' || s[i] == '/')
          {
            if (!st.empty() && st.top() != '+' && st.top() != '-' && st.top() != '(')
            {
              post_eval.push_back(string() + st.top());
              st.pop();
            }
            st.push(s[i]);
          }
        }
      }
    }

    if (!result.empty())
    {
      post_eval.push_back(result);
    }
    while (!st.empty())
    {
      post_eval.push_back(string() + st.top());
      st.pop();
    }

    return post_eval;
  }

  bool IsNumber(string &s)
  {
    try
    {
      std::stoi(s);
      return true;
    }
    catch (exception &e)
    {
      return false;
    }
  }

  int calculateWithCommon(string s) {
    vector<string> result = In2Post(s);
    stack<int> st;
    int num = 0;
    for (int i = 0; i < result.size(); ++i)
    {
      if (IsNumber(result[i]))
      {
        st.push(std::stoi(result[i]));
      }
      else
      {
        int data2 = st.top();
        st.pop();
        int data1 = st.top();
        st.pop();
        if (result[i] == "+")
        {
          st.push(data1 + data2);
        }
        else if (result[i] == "-")
        {
          st.push(data1 - data2);
        }
        else if (result[i] == "*")
        {
          st.push(data1 * data2);
        }
        else if (result[i] == "/")
        {
          st.push(data1 / data2);
        }
      }
    }

    return st.top();
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
