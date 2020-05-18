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
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    vector<string> word_dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    vector<string> result = wordBreak(s, word_dict);
    Show(result);
  }

  bool Valid(vector<string>& wordDict, string &item)
  {
    for (string &word : wordDict)
    {
      if (item == word)
      {
        return true;
      }
    }

    return false;
  }

  vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> result;
    Aux(s, wordDict, 0, "", result);

    return result;
  }

  bool Aux(string &s, vector<string>& wordDict, int pos, string cur_str, vector<string> &result)
  {
    int s_size = s.size();
    if (pos == s_size)
    {
      result.push_back(cur_str);
      return true;
    }

    for (int i = 1; i <= s_size - pos; ++i)
    {
      string item = s.substr(pos, i);
      if (Valid(wordDict, item))
      {
        Aux(s, wordDict, pos + i, cur_str == "" ? item : cur_str + " " + item, result);
      }
    }

    return false;
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
