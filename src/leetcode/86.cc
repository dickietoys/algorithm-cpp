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
    input->next = new ListNode(4);
    input->next->next = new ListNode(3);
    input->next->next->next = new ListNode(2);
    input->next->next->next->next = new ListNode(5);
    input->next->next->next->next->next = new ListNode(2);
    Show(input);
    result = partition(input, 3);
    Show(result);
  }

  ListNode* partition(ListNode* head, int x) {
    ListNode dummy1(0);
    ListNode dummy2(0);

    ListNode *node1 = &dummy1;
    ListNode *node2 = &dummy2;
    ListNode *cur = head;
    while (cur)
    {
      if (cur->val < x)
      {
        node1->next = cur;
        node1 = node1->next;
      }
      else
      {
        node2->next = cur;
        node2 = node2->next;
      }

      cur = cur->next;
    }
    node1->next = nullptr;
    node2->next = nullptr;
    node1->next = dummy2.next;

    return dummy1.next;
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
