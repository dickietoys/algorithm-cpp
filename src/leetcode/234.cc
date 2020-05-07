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

class Solution {
 public:
  void RunTest()
  {
  }

  bool isPalindrome(ListNode* head) {
    if (!head)
    {
      return false;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next)
    {
      fast = fast->next;
      if (fast->next)
      {
        fast = fast->next;
        slow = slow->next;
      }
    }

    ListNode *prev = nullptr;
    ListNode *cur = slow->next;
    ListNode *next = nullptr;
    while (cur)
    {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    slow->next = nullptr;
    ListNode *node1 = head;
    ListNode *node2 = prev;
    while (node1 && node2)
    {
      if (node1->val != node2->val)
      {
        return false;
      }

      node1 = node1->next;
      node2 = node2->next;
    }

    return true;
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
