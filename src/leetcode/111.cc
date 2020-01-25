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
    int result;
    input = new TreeNode(3);
    input->left = new TreeNode(9);
    input->right = new TreeNode(20);
    input->right->left = new TreeNode(15);
    input->right->right = new TreeNode(7);

    result = minDepth(input);
    cout << result << endl;
  }

  int minDepth(TreeNode* root) {
    return Aux(root);
  }

  int Aux(TreeNode *node)
  {
    if (!node)
    {
      return 0;
    }

    int left = Aux(node->left);
    int right = Aux(node->right);

    return (left == 0 || right == 0) ? left + right + 1 : std::min(left, right) + 1;
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
