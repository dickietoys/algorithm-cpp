#ifndef FIND_MINIMUM_DEPTH_OF_BINARY_TREE_H_
#define FIND_MINIMUM_DEPTH_OF_BINARY_TREE_H_

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <algorithm>

#include <testsuit/TestBase.h>
#include <tree_heap/BinarySearchTree.h>

using namespace std;

class FindMinimumDepthOfBinaryTree: public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================FindMinimumDepthOfBinaryTree====================" << endl;
    BinarySearchTree myTree;
    myTree.Insert(4);
    myTree.Insert(2);
    myTree.Insert(5);
    myTree.Insert(1);
    myTree.Insert(3);
    myTree.ShowLevelOrder(true);
    cout << "MinimumDepth: " << myTree.MinimumDepth() << endl;
    cout << "MinimumDepthRecursive: " << myTree.MinimumDepthRecursive() << endl;
    cout << "=================FindMinimumDepthOfBinaryTree====================" << endl;
  }
};

#endif
