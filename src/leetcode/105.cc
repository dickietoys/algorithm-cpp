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

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int inorderSize = inorder.size();
    return BuildAux(preorder, 0, inorder, 0, inorderSize - 1);
  }

  int FindPos(vector<int> &arr, int start, int end, int val)
  {
    int i = 0;
    for (i = start; i <= end; ++i)
    {
      if (arr[i] == val)
      {
        return i;
      }
    }

    return i;
  }

  TreeNode* BuildAux(vector<int>& preorder, int preorderIndex, vector<int>& inorder, int inorderLeftPos, int inorderRightPos)
  {
    if (inorderLeftPos > inorderRightPos)
    {
      return nullptr;
    }

    TreeNode *node = new TreeNode(preorder[preorderIndex]);
    int pos = FindPos(inorder, inorderLeftPos, inorderRightPos, node->val);

    node->left = BuildAux(preorder, preorderIndex + 1, inorder, inorderLeftPos, pos - 1);
    node->right = BuildAux(preorder, preorderIndex + pos - inorderLeftPos + 1, inorder, pos + 1, inorderRightPos);

    return node;
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
