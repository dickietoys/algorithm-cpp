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
    bool result;

    input = new TreeNode(2);
    input->left = new TreeNode(1);
    input->right = new TreeNode(3);
  }

  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    bool negative = false;
    vector<vector<int>> order;
    if (!root)
    {
      return order;
    }
    deque<TreeNode *> q;
    q.push_back(root);
    while (!q.empty())
    {
      vector<int> item;
      int size = q.size();
      while(size--)
      {
        TreeNode *node = q.front();
        q.pop_front();
        item.push_back(node->val);
        if (node->left)
        {
          q.push_back(node->left);
        }
        if (node->right)
        {
          q.push_back(node->right);
        }
      }
      if (negative)
      {
        std::reverse(item.begin(), item.end());
      }
      negative = !negative;
      order.push_back(item);
    }

    return order;
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
