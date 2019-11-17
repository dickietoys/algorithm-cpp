#ifndef MERGE_TWO_SORTED_LINKED_LIST_H
#define MERGE_TWO_SORTED_LINKED_LIST_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <linkedlist/LinkedList.h>

using namespace std;

class MergeTwoSortedLinkedList : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================MergeTwoSortedLinkedList====================" << endl;
    LinkedList linkedList;
    linkedList.PushBack(1);
    linkedList.PushBack(3);
    linkedList.PushBack(5);
    linkedList.PushBack(7);
    linkedList.Show();
    LinkedList linkedList1;
    linkedList1.PushBack(2);
    linkedList1.PushBack(4);
    linkedList1.PushBack(6);
    linkedList1.PushBack(8);
    linkedList.MergeSortedLinkedList(linkedList1.GetHeader());
    linkedList.Show();

    cout << "=================MergeTwoSortedLinkedList====================" << endl;
  }
};

#endif
