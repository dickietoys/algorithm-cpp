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
    vector<vector<int>> triangle = {{-1}, {2, 3}, {1, -1, -3}};
    int result = minimumTotal(triangle);

    cout << "result: " << result << endl;
  }

  int Aux(vector<vector<int>>& triangle, int row, int col)
  {
    if (row >= triangle.size())
    {
      return 0;
    }

    int sum1 = triangle[row][col] +
               // Aux(triangle, row + 1, col);
               std::min(Aux(triangle, row + 1, col),
                        Aux(triangle, row + 1, col + 1));

    if (col+1 < triangle[row].size())
    {
      int sum2 = triangle[row][col+1] +
                 // Aux(triangle, row + 1, col + 1);
             std::min(Aux(triangle, row + 1, col+1),
                      Aux(triangle, row + 1, col+2));
      cout << triangle[row][col] << ", " << triangle[row][col+1] << ", sum1: " << sum1 << ", sum2: " << sum2 << endl;
      return std::min(sum1, sum2);
    }
    else
    {
      cout << triangle[row][col] << ", sum1: " << sum1 << endl;
      return sum1;
    }
  }

  int minimumTotal(vector<vector<int>>& triangle) {
    return Aux(triangle, 0, 0);
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
