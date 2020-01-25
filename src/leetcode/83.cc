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

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  void RunTest()
  {
    ListNode *input;
    ListNode *result;

    input = new ListNode(1);
    input->next = new ListNode(2);
    input->next->next = new ListNode(3);
    input->next->next->next = new ListNode(3);
    input->next->next->next->next = new ListNode(4);
    input->next->next->next->next->next = new ListNode(4);
    input->next->next->next->next->next->next = new ListNode(5);
    result = deleteDuplicates(input);
    Show(result);
  }

  void Show(ListNode* head)
  {
    while (head)
    {
      cout << head->val << ", ";
      head = head->next;
    }

    cout << endl;
  }

  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next)
    {
      return head;
    }

    ListNode *prev = head;
    ListNode *cur = head->next;
    while (cur)
    {
      while (cur && prev->val == cur->val)
      {
        cur = cur->next;
      }

      prev->next = cur;
      prev = prev->next;
      if (cur)
      {
        cur = cur->next;
      }
    }

    return head;
  }

  void Show(vector<int> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
  }

  void Show(vector<vector<int>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ",";
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
