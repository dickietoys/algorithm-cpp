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
#include <bitset>

using namespace std;

class Solution {
 public:
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

  void RunTest()
  {
    TreeNode *input;
    vector<int> result;


    result = inorderTraversal(input);
    Show(result);
  }


  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    Aux(root, result);
    return result;
  }

  vector<int> StackAux(TreeNode* root)
  {
    vector<int> result;
    stack<TreeNode *> s;
    while (root || !s.empty())
    {
      while (root)
      {
        s.push(root);
        root = root->left;
      }

      root = s.top();
      s.pop();
      result.push_back(root->val);
      root = root->right;
    }

    return result;
  }

  void Aux(TreeNode* node, vector<int> &result)
  {
    if (!node)
    {
      return;
    }

    Aux(node->left, result);
    result.push_back(node->val);
    Aux(node->right, result);
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
