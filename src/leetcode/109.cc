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

  struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };

  void RunTest()
  {
    ListNode *input;
    bool result;

    input = new ListNode(-10);
    input->next = new ListNode(-3);
    input->next->next = new ListNode(0);
    input->next->next->next = new ListNode(5);
    input->next->next->next->next = new ListNode(9);
  }

  TreeNode* sortedListToBST(ListNode* head) {
    if (!head)
    {
      return nullptr;
    }

    return Aux(head, nullptr);
  }

  TreeNode* Aux(ListNode *head, ListNode *tail)
  {
    if (head == tail)
    {
      return nullptr;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != tail && fast->next != tail)
    {
      fast = fast->next->next;
      slow = slow->next;
    }

    TreeNode *node = new TreeNode(slow->val);
    node->left = Aux(head, slow);
    node->right = Aux(slow->next, tail);

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
