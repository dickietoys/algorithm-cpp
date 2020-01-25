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

  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int inSize = inorder.size();
    int postSize = postorder.size();
    return Aux(inorder, 0, inSize - 1, postorder, 0, postSize - 1);
  }

  int FindPos(vector<int> &arr, int val)
  {
    int i = 0;
    for (i = 0; i < arr.size(); ++i)
    {
      if (arr[i] == val)
      {
        return i;
      }
    }

    return i;
  }

  TreeNode *Aux(vector<int> &inorder,
                int iStart,
                int iEnd,
                vector<int> &postorder,
                int pStart,
                int pEnd)
  {
    if (iStart > iEnd || pStart > pEnd)
    {
      return nullptr;
    }

    TreeNode *node = new TreeNode(postorder[pEnd]);
    int pos = FindPos(inorder, node->val);
    node->left = Aux(inorder, iStart, pos - 1, postorder, pStart, pStart + pos - iStart - 1);
    node->right = Aux(inorder, pos + 1, iEnd, postorder, pEnd - (iEnd - pos), pEnd - 1);

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
