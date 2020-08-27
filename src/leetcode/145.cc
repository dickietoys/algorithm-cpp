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
  }

  vector<int> postorderTraversal(TreeNode* root) {
    if (!root)
    {
      return {};
    }

    vector<int> result;
    stack<TreeNode *> st;
    st.push(root);
    TreeNode *last_pop = root;
    TreeNode *cur = nullptr;
    while (!st.empty())
    {
      cur = st.top();
      if (cur->left && cur->left != last_pop && cur->right != last_pop)
      {
        st.push(cur->left);
      }
      else if (cur->right && cur->right != last_pop)
      {
        st.push(cur->right);
      }
      else
      {
        result.push_back(cur->val);
        last_pop = cur;
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
