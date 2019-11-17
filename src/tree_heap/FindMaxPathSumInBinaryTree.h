#ifndef FIND_MAX_PATH_SUM_IN_BINARY_TREE_H_
#define FIND_MAX_PATH_SUM_IN_BINARY_TREE_H_

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <algorithm>

#include <testsuit/TestBase.h>
#include <tree_heap/BinaryTree.h>

using namespace std;

class FindMaxPathSumInBinaryTree: public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================FindMaxPathSumInBinaryTree====================" << endl;
    BinaryTree myTree;
    TreeNodeT *root = myTree.InitRoot(10);
    TreeNodeT *node = myTree.InsertLeft(root, 2);
    myTree.InsertLeft(node, 20);
    myTree.InsertRight(node, 1);
    node = myTree.InsertRight(root, 10);
    node = myTree.InsertRight(node, -25);
    myTree.InsertLeft(node, 3);
    myTree.InsertRight(node, 4);
    cout << myTree.MaxPathSum() << endl;
    cout << "=================FindMaxPathSumInBinaryTree====================" << endl;
  }
};

#endif
