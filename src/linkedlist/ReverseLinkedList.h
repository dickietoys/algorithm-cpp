#ifndef REVERSE_LINKED_LIST_H
#define REVERSE_LINKED_LIST_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <linkedlist/LinkedList.h>

using namespace std;

class ReverseLinkedList : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================ReverseLinkedList====================" << endl;
    LinkedList linkedList;
    linkedList.PushBack(1);
    linkedList.PushBack(2);
    linkedList.PushBack(3);
    linkedList.PushBack(4);
    linkedList.PushBack(5);
    linkedList.Show();
    linkedList.Reverse();
    linkedList.Show();

    cout << "=================ReverseLinkedList====================" << endl;
  }
};

#endif
