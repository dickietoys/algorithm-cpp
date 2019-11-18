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
    MergeSortAux(&(head_->next));
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
    Show(curNode);
  }

  void SplitList(ListNodeT *startNode, ListNodeT **rightStartNode)
  {
    ListNodeT *fast = startNode;
    ListNodeT *slow = startNode;
    while (fast)
    {
      fast = fast->next;
      if (fast && fast->next)
      {
        fast = fast->next;
        slow = slow->next;
      }
    }

    *rightStartNode = slow->next;
    slow->next = nullptr;
  }

 private:
  void Show(ListNodeT *curNode)
  {
    while (curNode)
    {
      cout << curNode->value << ", ";
      curNode = curNode->next;
    }

    cout << endl;
  }

  void MergeSortAux(ListNodeT **node)
  {
    ListNodeT *curNode = *node;
    if (!curNode || !curNode->next)
    {
      return;
    }

    ListNodeT *rightStartNode = nullptr;
    SplitList(curNode, &rightStartNode);
    MergeSortAux(&curNode);
    MergeSortAux(&rightStartNode);
    Merge(&curNode, rightStartNode);
    *node = curNode;
  }

  void Merge(ListNodeT **node1, ListNodeT *node2)
  {
    ListNodeT *startNode = *node1;
    ListNodeT dummy;
    ListNodeT *curNode = &dummy;
    while (startNode && node2)
    {
      if (startNode->value > node2->value)
      {
        curNode->next = node2;
        node2 = node2->next;
        curNode = curNode->next;
      }
      else
      {
        curNode->next = startNode;
        startNode = (startNode)->next;
        curNode = curNode->next;
      }
    }

    while (startNode)
    {
      curNode->next = startNode;
      startNode = (startNode)->next;
      curNode = curNode->next;
    }

    while (node2)
    {
      curNode->next = node2;
      node2 = node2->next;
      curNode = curNode->next;
    }

    *node1 = dummy.next;
    Show(dummy.next);
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
