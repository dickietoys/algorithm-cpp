#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <queue>

#include <testsuit/TestBase.h>

using namespace std;

typedef struct TreeNodeS{
  int value;
  TreeNodeS *left;
  TreeNodeS *right;
} TreeNodeT;

class Tree
{
 public:
  Tree() :
      root_(nullptr),
      size_(0)
  {}

  void Insert(int value)
  {
    TreeNodeT *newNode = new TreeNodeT({value, nullptr, nullptr});
    if (root_)
    {
      TreeNodeT *curNode = root_;
      while (true)
      {
        if (value > curNode->value)
        {
          if (curNode->right == nullptr)
          {
            curNode->right = newNode;
            break;
          }
          else
          {
            curNode = curNode->right;
          }
        }
        else
        {
          if (curNode->left == nullptr)
          {
            curNode->left = newNode;
            break;
          }
          else
          {
            curNode = curNode->left;
          }
        }
      }
    }
    else
    {
      root_ = newNode;
    }

    ++size_;
  }

  void ShowPreOrder()
  {
    ShowPreOrder(root_);
    cout << endl;
  }

  void ShowInOrder()
  {
    ShowInOrder(root_);
    cout << endl;
  }

  void ShowPostOrder()
  {
    ShowPostOrder(root_);
    cout << endl;
  }

  void ShowLevelOrder()
  {
    ShowLevelOrder(root_);
    cout << endl;
  }

 private:
  void ShowPreOrder(TreeNodeT *node)
  {
    if (node != nullptr)
    {
      cout << node->value << ", ";
      ShowPreOrder(node->left);
      ShowPreOrder(node->right);
    }
  }

  void ShowInOrder(TreeNodeT *node)
  {
    if (node != nullptr)
    {
      ShowInOrder(node->left);
      cout << node->value << ", ";
      ShowInOrder(node->right);
    }
  }

  void ShowPostOrder(TreeNodeT *node)
  {
    if (node != nullptr)
    {
      ShowPostOrder(node->left);
      ShowPostOrder(node->right);
      cout << node->value << ", ";
    }
  }

  void ShowLevelOrder(TreeNodeT *node)
  {
    queue<TreeNodeT *> nodeQueue;
    nodeQueue.push(node);
    while (!nodeQueue.empty())
    {
      node = nodeQueue.front();
      nodeQueue.pop();
      cout << node->value << ", ";
      if (node->left)
      {
        nodeQueue.push(node->left);
      }

      if (node->right)
      {
        nodeQueue.push(node->right);
      }
    }
  }

 private:
  TreeNodeT *root_;
  int size_;
};


class TreeTest: public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================HeapTest====================" << endl;
    Tree myTree;
    myTree.Insert(5);
    myTree.Insert(2);
    myTree.Insert(8);
    myTree.Insert(1);
    myTree.Insert(3);
    myTree.Insert(6);
    myTree.Insert(7);
    myTree.Insert(4);

    myTree.ShowPreOrder();
    myTree.ShowInOrder();
    myTree.ShowPostOrder();
    myTree.ShowLevelOrder();
    cout << "=================HeapTest====================" << endl;
  }
};

#endif
