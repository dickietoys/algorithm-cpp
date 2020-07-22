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
  }

  bool IsValid(string &s, int low, int high)
  {
    int size = high - low + 1;
    if (size > 3 || (s[low] == '0' && size > 1) || std::stoi(s.substr(low, high - low + 1))  > 255)
    {
      return false;
    }
    else
    {
      return true;
    }
  }

  void Aux(string &s, int pos, int count, vector<string> &item, vector<string> &result)
  {
    if (pos >= s.size() && count == 4)
    {
      string s;
      for (string &tmp : item)
      {
        s += tmp + ".";
      }
      s = s.substr(0, s.size() - 1);
      result.push_back(s);
      return;
    }


    for (int i = pos; i < s.size(); ++i)
    {
      if (i - pos + 1 > 3)
      {
        break;
      }

      if (IsValid(s, pos, i))
      {
        item.push_back(s.substr(pos, i - pos + 1));
        Aux(s, i + 1, count + 1, item, result);
        item.pop_back();
      }
    }
  }

  vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    if (s.size() > 12)
    {
      return result;
    }
    vector<string> item;
    Aux(s, 0, 0, item, result);

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
