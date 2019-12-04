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
    ListNode* input;
    ListNode* result;

    input = new ListNode(1);
    input->next = new ListNode(2);
    input->next->next = new ListNode(3);
    input->next->next->next = new ListNode(4);
    input->next->next->next->next = new ListNode(5);
    cout << "origin: ";
    Show(input);
    result = rotateRight(input, 2);
    cout << "result: ";
    Show(result);

    input = new ListNode(0);
    input->next = new ListNode(1);
    input->next->next = new ListNode(2);
    cout << "origin: ";
    Show(input);
    result = rotateRight(input, 4);
    cout << "result: ";
    Show(result);
  }

  ListNode * rotateRight(ListNode *head, int k) {
    if (!head)
    {
      return head;
    }

    ListNode *tail = nullptr;
    ListNode *node = head;
    int size = 0;
    while (node)
    {
      ++size;
      if (node->next)
      {
        node = node->next;
      }
      else
      {
        tail = node;
        break;
      }
    }

    k = k % size;
    tail->next = head;
    node = head;
    ListNode *prevNode = nullptr;
    for (int i = 1; i <= size - k; ++i)
    {
      prevNode = node;
      node = node->next;
    }
    if (!prevNode)
    {
      return head;
    }
    else
    {
      prevNode->next = nullptr;
      return node;
    }
  }

  void Show(ListNode *node)
  {
    while (node)
    {
      cout << node->val << ", ";
      node = node->next;
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
