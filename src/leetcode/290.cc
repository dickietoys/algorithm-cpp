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

  std::vector<std::string> split(std::string strToSplit, char delimeter)
  {
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter))
    {
      splittedStrings.push_back(item);
    }
    return splittedStrings;
  }

  bool wordPattern(string pattern, string str) {
    vector<string> s = split(str, ' ');
    if (pattern.size() != s.size())
    {
      return false;
    }

    unordered_map<char, int> p_urmap;
    unordered_map<string, int> str_urmap;
    for (int i = 0; i < s.size(); ++i)
    {
      if (p_urmap[pattern[i]] != str_urmap[s[i]])
      {
        return false;
      }

      if (p_urmap[pattern[i]] == 0)
      {
        p_urmap[pattern[i]] = i;
        str_urmap[s[i]] = i;
      }
    }

    return true;
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
