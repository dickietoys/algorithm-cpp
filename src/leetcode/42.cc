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
#include <functional>

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

// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//         left = NULL;
//         right = NULL;
//     }

//     Node(int _val, Node* _left, Node* _right) {
//         val = _val;
//         left = _left;
//         right = _right;
//     }
// };


class Solution {
 public:
  void RunTest()
  {
  }

  /*
    [0,1,0,2,1,0,1,3,2,1,2,1]
             1
         1   11 1
      _1_11_111111
  */

  int trapWithStack(vector<int>& height) {
    if (height.empty())
    {
      return 0;
    }

    int sum = 0;
    stack<int> st;
    for (int i = 0; i < height.size(); ++i)
    {
      while (!st.empty() && height[st.top()] < height[i])
      {
        int right_pos = i;
        int cur_pos = st.top();
        st.pop();
        if (!st.empty())
        {
          int left_pos = st.top();
          int right_height = height[right_pos];
          int left_height = height[left_pos];

          int tmp_width = right_pos - left_pos - 1;
          int tmp_height = std::min(left_height, right_height) - height[cur_pos];
          sum += tmp_width * tmp_height;
        }
      }

      st.push(i);
    }

    return sum;
  }

  int trap(vector<int>& height) {
    if (height.empty())
    {
      return 0;
    }

    vector<int> dp_max_left(height.size(), 0);
    vector<int> dp_max_right(height.size(), 0);
    for (int i = 1; i < height.size() - 1; ++i)
    {
      dp_max_left[i] = std::max(dp_max_left[i-1], height[i-1]);
    }

    for (int i = height.size() - 2; i > 0; --i)
    {
      dp_max_right[i] = std::max(dp_max_right[i+1], height[i+1]);
    }

    int sum = 0;

    for (int i = 1; i < height.size() - 1 ; ++i)
    {
      int min_height = std::min(dp_max_left[i], dp_max_right[i]);
      if (min_height > height[i])
      {
        sum += min_height - height[i];
      }
    }

    return sum;
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
