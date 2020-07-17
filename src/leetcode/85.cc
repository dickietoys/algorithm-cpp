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

class Solution {
 public:
  void RunTest()
  {

  }

  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty())
    {
      return 0;
    }
    int max = 0;
    int rows = matrix.size() - 1;
    int cols = matrix[0].size() - 1;
    vector<int> heights(matrix[0].size() + 1, 0);
    for (int i = 0; i <= rows; ++i)
    {
      for (int j = 0; j <= cols; ++j)
      {
        if (matrix[i][j] == '1')
        {
          heights[j] += 1;
        }
        else
        {
          heights[j] = 0;
        }
      }

      stack<int> st;
      for (int k = 0; k < heights.size(); ++k)
      {
        while (!st.empty() && heights[st.top()] > heights[k])
        {
          int h = heights[st.top()];
          st.pop();
          int w = 0;
          if (st.empty())
          {
            w = k;
          }
          else
          {
            w = k - st.top() - 1;
          }
          max = std::max(max, h * w);
        }
        st.push(k);
      }
    }

    return max;
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", " << endl;
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
        cout << result[i][j] << ", " << endl;
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
