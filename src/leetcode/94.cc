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
    if (!root)
    {
      return {};
    }

    vector<int> result;
    stack<TreeNode *> st;
    st.push(root);
    TreeNode *last_pop = root;
    while (!st.empty())
    {
      TreeNode *node = st.top();
      if (node->left && node->left != last_pop && node->right != last_pop)
      {
        st.push(node->left);
      }
      else if (node->right && node->right != last_pop)
      {
        result.push_back(node->val);
        st.push(node->right);
      }
      else
      {
        if (!node->right)
        {
          result.push_back(node->val);
        }

        last_pop = node;
        st.pop();
      }
    }

    return result;
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
