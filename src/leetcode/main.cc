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
    int result = findNthDigit(11);
    cout << "---------------------result-----------------------" << endl;
    cout << "result: " << result << endl;
  }

  /*
    012345678910111213..99

    9             [1 ... 9]
    90 * 2        [10 ... 99]
    900 * 3       [100 ... 999]
   */
  int NumOfDigit(int n)
  {
    int count = 0;
    while (n)
    {
      ++count;
      n = n / 10;
    }

    return count;
  }

  int findNthDigit(int n) {
    if (n == 0)
    {
      return 0;
    }

    long num = 9;
    int factor = 1;
    while (true)
    {
      if (n <= num * factor)
      {
        break;
      }
      else
      {
        n = n - num * factor;
        num = num * 10;
        ++factor;
      }
    }

    long start_num = num / 9;
    long target_num = std::ceil(double(n) / factor) + start_num - 1;
    cout << "n: " << n << ", [" << start_num << ", " << target_num << "]" << endl;
    n = (target_num - start_num) * factor - n;


    string s = std::to_string(num);
    return s[n-1] - '0';
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
