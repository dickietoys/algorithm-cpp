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
  }

  bool is_symbols(string &s)
  {
    if (s == "+" || s == "-" || s == "*" || s == "/")
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  int evalRPN(vector<string>& tokens) {
    stack<string> s;
    for (auto it = tokens.begin(); it != tokens.end(); ++it)
    {
      if (is_symbols(*it))
      {
        int second_number = std::stoi(s.top());
        s.pop();
        int first_number = std::stoi(s.top());
        s.pop();
        if (*it == "+")
        {
          int value = first_number + second_number;
          s.push(std::to_string(value));
        }
        else if (*it == "-")
        {
          int value = first_number - second_number;
          s.push(std::to_string(value));
        }
        else if (*it == "*")
        {
          int value = first_number * second_number;
          s.push(std::to_string(value));
        }
        else if (*it == "/")
        {
          int value = first_number / second_number;
          s.push(std::to_string(value));
        }
      }
      else
      {
        s.push(*it);
      }
    }

    return std::stoi(s.top());
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
