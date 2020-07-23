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

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
 public:
  void RunTest()
  {
    // "aab"
    // "c*a*b"
    bool result = isMatch("aa", "a*");
    cout << "result: " << result << endl;
  }

  bool Aux(string &s, string &p, int s_pos, int p_pos)
  {
    if (s_pos < 0 && p_pos < 0)
    {
      return true;
    }

    if (s_pos < 0)
    {
      if (p[p_pos] == '*')
      {
        return Aux(s, p, s_pos, p_pos - 2);
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }

    if (p[p_pos] == '*')
    {
      if (p[p_pos - 1] == '.' || p[p_pos - 1] == s[s_pos])
      {
        return Aux(s, p, s_pos, p_pos - 2) || Aux(s, p, s_pos - 1, p_pos);
      }
      else
      {
        return false;
      }
    }
    else
    {
      if (p[p_pos] == '.' || p[p_pos] == s[s_pos])
      {
        return Aux(s, p, s_pos - 1, p_pos - 1);
      }
      else
      {
        return false;
      }
    }
  }

  bool isMatch(string s, string p)
  {
    return Aux(s, p, s.size() - 1, p.size() - 1);
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
