#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>
#include <testsuit/TestBase.h>

using namespace std;

typedef struct ListNodeS{
  int value;
  ListNodeS *next;
} ListNodeT;

class LinkedList
{
 public:
  LinkedList() :
      head_(new ListNodeT({0, nullptr})),
      tail_(head_),
      size_(0)
  {}

  ListNodeT *PushBack(int value)
  {
    tail_->next = new ListNodeT({value, nullptr});
    tail_ = tail_->next;
    ++size_;
    return tail_;
  }

  ListNodeT *InsertAfter(ListNodeT *prevNode, int value)
  {
    ListNodeT *newNode = new ListNodeT({value, nullptr});
    newNode->next = prevNode->next;
    prevNode->next = newNode;

    return newNode;
  }

  void MergeSortedLinkedList(ListNodeT *sortedListHead)
  {
    ListNodeT *listNode1 = head_->next;
    ListNodeT *listNode2 = sortedListHead->next;
    ListNodeT dummy;
    ListNodeT *tail = &dummy;
    dummy.next = nullptr;
    while (true)
    {
      if (!listNode1)
      {
        tail->next = listNode2;
        break;
      }

      if (!listNode2)
      {
        tail->next = listNode1;
        break;
      }

      if (listNode1->value <= listNode2->value)
      {
        tail->next = listNode1;
        tail = tail->next;
        listNode1 = listNode1->next;
      }
      else
      {
        tail->next = listNode2;
        tail = tail->next;
        listNode2 = listNode2->next;
      }
    }
    head_->next = dummy.next;
  }

  ListNodeT *GetHeader()
  {
    return head_;
  }

  void Reverse()
  {
    if (!head_->next)
    {
      return;
    }
    ListNodeT *cur = head_->next;
    ListNodeT *prev = nullptr;
    ListNodeT *next = nullptr;
    while (cur)
    {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    head_->next = prev;
  }

  void MergeSort()
  {

  }

  void FindMiddle(ListNodeT **middleNode)
  {
    ListNodeT *slow = head_->next;
    ListNodeT *fast = head_->next;
    while (fast)
    {
      fast = fast->next;
      if (fast && fast->next)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }

    *middleNode = slow;
  }

  void Show()
  {
    ListNodeT *curNode = head_->next;
    while (curNode)
    {
      cout << curNode->value << ", ";
      curNode = curNode->next;
    }

    cout << endl;
  }

 private:
  void MergeSortAux(ListNodeT *leftNode, ListNodeT *rightNode)
  {

  }

 private:
  ListNodeT *head_;
  ListNodeT *tail_;
  int size_;
};


class LinkedListTest: public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================LinkedListTest====================" << endl;
    cout << "=================LinkedListTest====================" << endl;
  }
};

#endif
