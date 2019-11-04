#ifndef EXPRESSION_CONVERT_H_
#define EXPRESSION_CONVERT_H_

#include <vector>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

class expression_convert
{
 public:
  string infix2postfix(string & infix_expression)
  {
    stringstream postfix_expression;
    stack<char> s;
    for (string::size_type i = 0; i < infix_expression.size(); ++i)
    {
      if (infix_expression[i] == '+' or infix_expression[i] == '-')
      {
        if (s.empty())
        {
          s.push(infix_expression[i]);
        }
        else
        {
          while (!s.empty() && s.top() != '(')
          {
            postfix_expression.put(s.top());
            s.pop();
          }
          s.push(infix_expression[i]);
        }
      }
      else if (infix_expression[i] == '*' or infix_expression[i] == '/')
      {
        if (s.empty())
        {
          s.push(infix_expression[i]);
        }
        else
        {
          while (!s.empty() && s.top() != '(' && s.top() != '+' && s.top() != '-')
          {
            postfix_expression.put(s.top());
            s.pop();
          }
          s.push(infix_expression[i]);
        }
      }
      else if (infix_expression[i] == '(')
      {
        s.push(infix_expression[i]);
      }
      else if (infix_expression[i] == ')')
      {
        while (!s.empty())
        {
          if (s.top() == '(')
          {
            s.pop();
            break;
          }
          else
          {
            postfix_expression.put(s.top());
            s.pop();
          }
        }
      }
      else
      {
        postfix_expression.put(infix_expression[i]);
      }
    }

    while (!s.empty())
    {
      postfix_expression.put(s.top());
      s.pop();
    }

    return postfix_expression.str();
  }
};


#endif
