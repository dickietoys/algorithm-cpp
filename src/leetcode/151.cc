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

  string reverseWords(string s) {
    stack<string> st;
    int word_start_pos = -1;
    int pos = 0;
    s.append(" ");
    for (pos = 0; pos < s.size(); ++pos)
    {
      if (s[pos] == ' ')
      {
        if (word_start_pos != -1)
        {
          st.push(s.substr(word_start_pos, pos - word_start_pos));
          word_start_pos = -1;
        }
      }
      else
      {
        if (word_start_pos == -1)
        {
          word_start_pos = pos;
        }
      }
    }

    string result = "";
    while (!st.empty())
    {
      result.append(" ");
      result.append(st.top());
      st.pop();
    }

    if (result.size() != 0)
    {
      return result.substr(1);
    }
    else
    {
      return result;
    }
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
