#ifndef MERGE_SORT_LINKED_LIST_H
#define MERGE_SORT_LINKED_LIST_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <linkedlist/LinkedList.h>

using namespace std;

class MergeSortLinkedList : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================MergeSortLinkedList====================" << endl;
    LinkedList linkedList;
    linkedList.PushBack(15);
    linkedList.PushBack(10);
    linkedList.PushBack(5);
    linkedList.PushBack(20);
    linkedList.PushBack(3);
    linkedList.PushBack(2);
    linkedList.PushBack(1);
    linkedList.Show();
    // linkedList.MergeSort();
    ListNodeT *middleNode = nullptr;
    linkedList.FindMiddle(&middleNode);
    cout << middleNode->value << endl;
    linkedList.Show();

    cout << "=================MergeSortLinkedList====================" << endl;
  }
};

#endif
