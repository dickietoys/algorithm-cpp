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
    vector<vector<string>> result;
    result = partition("aab");
  }

  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> item_result;
    Aux(s, 0, item_result, result);

    return result;
  }

  void Aux(string &s,
           int pos,
           vector<string> item_result,
           vector<vector<string>> &result)
  {
    if (pos >= s.size() && item_result.size() > 0)
    {
      result.push_back(item_result);
      return;
    }

    for (int i = pos; i < s.size(); ++i)
    {
      if (IsPalindrome(s, pos, i))
      {
        item_result.push_back(s.substr(pos, i - pos + 1));
        Aux(s, i + 1, item_result, result);
        item_result.pop_back();
      }
    }
  }

  bool IsPalindrome(string &s, int left_pos, int right_pos)
  {
    if (left_pos == right_pos)
    {
      return true;
    }

    while (left_pos < right_pos)
    {
      if (s[left_pos++] != s[right_pos--])
      {
        return false;
      }
    }

    return true;
  }

  void Show(vector<int> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
  }

  void Show(vector<vector<int>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ",";
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
