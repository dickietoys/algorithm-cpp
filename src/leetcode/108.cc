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

  TreeNode* sortedArrayToBST(vector<int>& nums) {
    int numsSize = nums.size();
    return Aux(nums, 0, numsSize - 1);
  }

  TreeNode *Aux(vector<int>& nums, int left, int right)
  {
    if (left > right)
    {
      return nullptr;
    }

    int middle = (left + right) / 2;
    TreeNode *node = new TreeNode(nums[middle]);
    node->left = Aux(nums, left, middle - 1);
    node->right = Aux(nums, middle + 1, right);

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
