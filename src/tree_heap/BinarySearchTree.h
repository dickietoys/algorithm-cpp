#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <iostream>
#include <queue>

#include <testsuit/TestBase.h>

using namespace std;

typedef struct TreeNodeS{
  int value;
  TreeNodeS *left;
  TreeNodeS *right;
} TreeNodeT;

class BinarySearchTree
{
 public:
  BinarySearchTree() :
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

  void ShowLevelOrder(bool pretty = false)
  {
    ShowLevelOrder(root_, pretty);
    cout << endl;
  }

  void ShowLevelOrderRecursive(bool pretty = false)
  {
    int treeHeight = Height();
    for (int i = 0; i < treeHeight; ++i)
    {
      ShowLevelOrderRecursive(root_, i);
      if (pretty)
      {
        cout << endl;
      }
    }

    cout << endl;
  }

  int Height()
  {
    if (root_ == nullptr)
    {
      return -1;
    }

    return Height(root_);
  }

  int MinimumDepth()
  {
    return MinimumDepthRecursive(root_);
  }

 private:
  int MinimumDepthRecursive(TreeNodeT *node)
  {
    if (node == nullptr)
    {
      return 0;
    }

    int leftDepth = 0;
    if (node->left)
    {
      leftDepth = MinimumDepthRecursive(node->left);
    }

    int rightDepth = 0;
    if (node->right)
    {
      rightDepth = MinimumDepthRecursive(node->right);
    }

    return std::min(leftDepth, rightDepth) + 1;
  }

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

  void ShowLevelOrder(TreeNodeT *node, bool pretty)
  {
    queue<TreeNodeT *> nodeQueue;
    nodeQueue.push(node);
    while (!nodeQueue.empty())
    {
      int curSize = nodeQueue.size();
      while (curSize != 0)
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
        --curSize;
      }

      if (pretty)
      {
        cout << endl;
      }
    }
  }

  void ShowLevelOrderRecursive(TreeNodeT *node, int level)
  {
    if (node == nullptr)
    {
      return;
    }

    if (level == 0)
    {
      cout << node->value << ", ";
    }
    else
    {
      ShowLevelOrderRecursive(node->left, level - 1);
      ShowLevelOrderRecursive(node->right, level - 1);
    }
  }

  int Height(TreeNodeT *node)
  {
    if (node == nullptr)
    {
      return 0;
    }

    return std::max(Height(node->left), Height(node->right)) + 1;
  }

 private:
  TreeNodeT *root_;
  int size_;
};


class BinarySearchTreeTest: public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================BinarySearchTreeTest====================" << endl;
    BinarySearchTree myTree;
    myTree.Insert(5);
    myTree.Insert(2);
    myTree.Insert(8);
    myTree.Insert(1);
    myTree.Insert(3);
    myTree.Insert(6);
    myTree.Insert(7);
    myTree.Insert(4);
    cout << "tree height:" << myTree.Height() << endl;

    myTree.ShowPreOrder();
    myTree.ShowInOrder();
    myTree.ShowPostOrder();
    myTree.ShowLevelOrder();
    myTree.ShowLevelOrderRecursive();

    myTree.ShowLevelOrder(true);
    myTree.ShowLevelOrderRecursive(true);
    cout << "=================BinarySearchTreeTest====================" << endl;
  }
};

#endif
