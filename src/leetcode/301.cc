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
  }

  bool is_valid(string &str)
  {
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
      if (str[i] == '(')
        cnt++;
      else if (str[i] == ')')
        cnt--;
      if (cnt < 0)
        return false;
    }
    return (cnt == 0);
  }

  vector<string> removeInvalidParentheses(string s) {
    vector<string> result;
    while(!s.empty())
    {
      if (s[0] != ')')
      {
        break;
      }
      s.erase(0, 1);
    }

    if (s.empty())
    {
      return result;
    }

    queue<string> q;
    set<string> visited;
    q.push(s);
    visited.insert(s);
    bool found = false;
    while (!q.empty())
    {
      s = q.front();
      q.pop();
      if (is_valid(s))
      {
        result.push_back(s);
        found = true;
        continue;
      }

      if (found)
      {
        continue;
      }

      for (int i = 0; i < s.size(); ++i)
      {
        if (s[i] != '(' && s[i] != ')')
        {
          continue;
        }
        string temp = s.substr(0, i) + s.substr(i + 1);
        if (!visited.count(temp))
        {
          q.push(temp);
          visited.insert(temp);
        }
      }
    }

    return result;
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", " << endl;
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
        cout << result[i][j] << ", " << endl;
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
