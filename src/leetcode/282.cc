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
    Aux(num, target, 0, 0, "", result);
    return result;
  }

  void Aux(string &num, int target, int pos, int cur_value, string item, vector<string> &result)
  {
    int num_size = num.size();
    if (num_size == 0)
    {
      return;
    }

    if (num_size == pos)
    {
      if (target == cur_value)
      {
        result.push_back(item);
      }

      return;
    }

    int cur = num[pos] - '0';
    if (pos == 0)
    {
      Aux(num, target, pos + 1, cur, item + num[pos], result);
    }
    else
    {
      Aux(num, target, pos + 1, cur_value + cur, item + "+" + num[pos], result);
      Aux(num, target, pos + 1, cur_value - cur, item + "-" + num[pos], result);
      Aux(num, target, pos + 1, cur_value * cur, item + "*" + num[pos], result);
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
