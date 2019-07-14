#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <iostream>

using namespace std;

template<class T>
class BinarySearchTree
{
 public:
  BinarySearchTree(){}

  BinarySearchTree(const BinarySearchTree &rhs)
  {
    root = clone(rhs.root);
  }

  ~BinarySearchTree()
  {
    makeEmpty();
  }

  const T & findMin() const
  {
    return findMin(root);
  }

  const T & findMax() const
  {
    return findMax(root);
  }

  bool contains(const T &x) const
  {
    return contains(x, root);
  }

  bool isEmpty() const
  {
    return root == nullptr;
  }

  void printTree(ostream & out = cout) const
  {}

  void makeEmpty()
  {
    makeEmpty(root);
  }

  void insert(const T & x)
  {
    insert(x, root);
  }

  void remove(const T & x)
  {
    remove(x, root);
  }

  BinarySearchTree & operator=(const BinarySearchTree &rhs)
  {}

 private:
  struct BinaryNode
  {
    T element;
    BinaryNode *left;
    BinaryNode *right;

    BinaryNode(const T &theElement, BinaryNode *lt, BinaryNode *rt)
    {
      element = theElement;
      left = lt;
      right = rt;
    }
  };

  BinaryNode *root;

  void insert(const T &x, BinaryNode * & t)
  {
    if (t == nullptr)
    {
      t = new BinaryNode(x, nullptr, nullptr);
    }

    if (x < t->element)
    {
      insert(x, t->left);
    }
    else if (x > t->element)
    {
      insert(x, t->right);
    }
  }

  void remove(const T &x, BinaryNode * & t)
  {
    if (t == nullptr)
    {
      return;
    }

    if (x < t->element)
    {
      remove(x, t->left);
    }
    else if (x > t->element)
    {
      remove(x, t->right);
    }
    else
    {
      if (t->left != nullptr && t->right != nullptr)
      {
        // 待删除的结点有两个孩子
        t->element = findMin(t->right);
        remove(t->element, t->right);
      }
      else
      {
        //待删除的结点至多一个孩子
        BinaryNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
      }
    }
  }

  BinaryNode * findMin(BinaryNode *t) const
  {
    if (t == nullptr)
    {
      return nullptr;
    }

    while (t->left)
    {
      t = t->left;
    }

    return t;
  }

  BinaryNode * findMax(BinaryNode *t) const
  {
    if (t == nullptr)
    {
      return nullptr;
    }

    while (t->right)
    {
      t = t->right;
    }

    return t;
  }

  bool contains(const T &x, BinaryNode *t) const
  {
    if (t == nullptr)
    {
      return false;
    }
    else if(x < t->element)
    {
      return contains(x, t->left);
    }
    else if (x > t->element)
    {
      return contains(x, t->right);
    }
    else
    {
      return true;
    }
  }

  void makeEmpty(BinaryNode * & t)
  {
    if (t != nullptr)
    {
      makeEmpty(t->left);
      makeEmpty(t->right);

      delete t;
    }

    t = nullptr;
  }

  void printTree(BinaryNode *t, ostream & out) const
  {}

  BinaryNode * clone(BinaryNode *t) const
  {
    if (t == nullptr)
    {
      return nullptr;
    }
    else
    {
      return new BinaryNode(t->element, clone(t->left), clone(t->right));
    }
  }

};

#endif
