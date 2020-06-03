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
#include <list>

using namespace std;

struct LinkedListNode
{
  int data;
  struct LinkedListNode *next;
  LinkedListNode()
      : data(0)
      , next(nullptr)
  {}

  LinkedListNode(int value)
      : data(value)
      , next(nullptr)
  {}
};

class LinkedList
{
 private:
  LinkedListNode *head_;
  LinkedListNode *tail_;
 public:
  LinkedList()
      :head_(new LinkedListNode())
      ,tail_(head_)
  {}

  void Insert(int value)
  {
    LinkedListNode *node = new LinkedListNode(value);
    tail_->next = node;
    tail_ = node;
  }

  void DeleteByPos(int pos)
  {
    LinkedListNode *prev = head_;
    LinkedListNode *cur = head_->next;
    int cur_pos = 0;
    while (cur)
    {
      if (cur_pos == pos)
      {
        prev->next = cur->next;
        if (cur == tail_)
        {
          tail_ = prev;
        }
        delete cur;
      }
      prev = cur;
      cur = cur->next;
      ++cur_pos;
    }
  }

  void DeleteByValue(int value)
  {
    LinkedListNode *prev = head_;
    LinkedListNode *cur = head_->next;
    while (cur)
    {
      if (cur->data == value)
      {
        prev->next = cur->next;
        if (cur == tail_)
        {
          tail_ = prev;
        }
        delete cur;
      }
      prev = cur;
      cur = cur->next;
    }
  }

  void Clear()
  {
    LinkedListNode *cur = head_->next;
    LinkedListNode *next = nullptr;
    while (cur)
    {
      next = cur->next;
      delete cur;
      cur = next;
    }

    head_->next = nullptr;
  }

  LinkedListNode * FindRKthNode(int kth)
  {
    LinkedListNode *slow = head_->next;
    LinkedListNode *fast = head_->next;
    while (kth && fast)
    {
      fast = fast->next;
      --kth;
    }

    if (kth != 0)
    {
      return nullptr;
    }

    while (fast)
    {
      fast = fast->next;
      slow = slow->next;
    }

    return slow;
  }

  void ShowList()
  {
    if (!head_->next)
    {
      cout << "empty" << endl;
      return;
    }

    LinkedListNode *node = head_->next;
    while (node)
    {
      cout << node->data << ", ";
      node = node->next;
    }

    cout << endl;
  }
};


class Solution {
 public:
  void RunTest()
  {
    LinkedList list;
    list.Insert(0);
    list.Insert(1);
    list.Insert(2);
    list.Insert(3);
    list.Insert(4);
    list.Insert(5);

    LinkedListNode *node = list.FindRKthNode(2);
    cout << (node ? node->data : -1) << endl;
    // list.ShowList();
    // list.DeleteByPos(2);
    // list.ShowList();
    // list.DeleteByValue(4);
    // list.ShowList();
    // list.Clear();
    // list.ShowList();
  }

  template<class T>
  void Show(const vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", " << endl;
    }
    cout << endl;
  }

  template<class T>
  void Show(const vector<vector<T>> &result)
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
