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

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

static int a = 0;

class Solution {
 public:
  void RunTest()
  {
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int result = removeElement(nums, 2);
    cout << result << endl;
  }

  int removeElement(vector<int>& nums, int val) {
    int start_pos = 0;
    int nums_size = nums.size();
    int total_count = nums_size;
    int valid_pos = 0;
    for (int i = 0; i < nums_size;)
    {
      if (nums[i] == val)
      {
        for (int j = i + 1; j < nums_size; ++j)
        {
          if (nums[j] != val)
          {
            nums[valid_pos++] = nums[j];
            total_count -= j - i;
            i = j + 1;
            break;
          }
        }
      }
      else
      {
        nums[valid_pos++] = nums[i++];
      }
    }

    return total_count;
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
  delete solution;
  return 0;
}
