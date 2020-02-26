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
    int input;
    vector<TreeNode *> result;

    result = generateTrees(input);
  }

  vector<TreeNode *> generateTrees(int n) {
    if (n <= 0)
    {
      return vector<TreeNode *>();
    }
    return Aux(1, n);
  }

  vector<TreeNode *> Aux(int startPos, int endPos)
  {
    vector<TreeNode *> rootArr;
    if (startPos > endPos)
    {
      rootArr.push_back(nullptr);
      return rootArr;
    }

    if (startPos == endPos)
    {
      rootArr.push_back(new TreeNode(startPos));
      return rootArr;
    }

    for (int i = startPos; i <= endPos; ++i)
    {
      vector<TreeNode *> left = Aux(startPos, i - 1);
      vector<TreeNode *> right = Aux(i + 1, endPos);

      for (auto leftIt = left.begin(); leftIt != left.end(); ++leftIt)
      {
        for (auto rightIt = right.begin(); rightIt != right.end(); ++rightIt)
        {
          TreeNode *root = new TreeNode(i);
          root->left = *leftIt;
          root->right = *rightIt;
          rootArr.push_back(root);
        }
      }
    }

    return rootArr;
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
