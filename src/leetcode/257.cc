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

  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    deque<int> dq;
    Aux(root, dq, result);
    return result;
  }

  string Convert(deque<int> &dq)
  {
    string s = "";
    for (auto v : dq)
    {
      s += std::to_string(v) + "->";
    }
    s = s.substr(0, s.size() - 2);

    return s;
  }

  void Aux(TreeNode *node, deque<int> &dq, vector<string> &result)
  {
    dq.push_back(node->val);
    if (node->left)
    {
      Aux(node->left, dq, result);
    }
    if (node->right)
    {
      Aux(node->right, dq, result);
    }
    if (!node->left && !node->right)
    {
      result.push_back(Convert(dq));
    }
    dq.pop_back();
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
