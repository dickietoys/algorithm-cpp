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

  vector<string> addOperators(string num, int target) {
    vector<string> result;
    if (num.size() <= 0)
    {
      return result;
    }

    Aux(num, target, 0, "", 0, 0, result);
    return result;
  }

  void Aux(string num, int target, int pos, string path, long cur_value, long prev_value, vector<string> &result)
  {
    if (pos == num.size())
    {
      if (cur_value == target)
      {
        result.push_back(path);
      }

      return;
    }

    for (int i = pos; i < num.size(); i++)
    {
      if (num[pos] == '0' && i != pos)
      {
        break;
      }
      string str_value = num.substr(pos, i - pos + 1);
      long value = std::stol(str_value);
      if (pos == 0)
      {
        Aux(num, target, i + 1, path + str_value, value, value, result);
      }
      else
      {
        Aux(num, target, i + 1, path + "+" + str_value, cur_value + value, value, result);
        Aux(num, target, i + 1, path + "-" + str_value, cur_value - value, -value, result);
        Aux(num, target, i + 1, path + "*" + str_value, cur_value - prev_value + prev_value * value, prev_value * value, result);
      }
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
