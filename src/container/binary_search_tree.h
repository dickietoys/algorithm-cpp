#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <iostream>
#include <stack>

using namespace std;

template<class T>
class BinarySearchTree
{
 public:
  BinarySearchTree(){
    root = nullptr;
  }

  BinarySearchTree(const BinarySearchTree &rhs)
  {
    root = clone(rhs.root);
  }

  int height() const
  {
    return height(root);
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

  void printTree(ostream & out = cout, int mode = 0) const
  {
    if (isEmpty())
    {
      out << "Empty tree" << endl;
    }
    else
    {
      printTree(root, out, mode);
    }
  }

  void printTree(stack<T> &s, int kth, int mode = 0) const
  {
    if (isEmpty())
    {
      return;
    }
    else
    {
      printTree(root, s, kth, mode);
    }
  }

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
  {
    root = clone(rhs.root);
  }

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

  int height(BinaryNode *t) const
  {
    if (t == nullptr)
    {
      return -1;
    }
    else
    {
      int leftMax = 1 + height(t->left);
      int rightMax = 1 + height(t->right);

      return leftMax > rightMax ? leftMax : rightMax;
    }
  }

  void insert(const T &x, BinaryNode * & t)
  {
    if (t == nullptr)
    {
      t = new BinaryNode(x, nullptr, nullptr);
      return;
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

    if (t->left == nullptr)
    {
      return t;
    }

    return findMin(t->left);
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

  void printTree(BinaryNode *t, stack<T> &s, int &kth, int mode) const
  {
    if (t == nullptr)
    {
      return;
    }

    if (mode == 0)
    {
      // preorder
      s.push(t->element);
      ++kth;
      printTree(t->left, s, kth, mode);
      printTree(t->right, s, kth, mode);
    }
    else if (mode == 1)
    {
      // inorder
      printTree(t->left, s, kth, mode);
      s.push(t->element);
      ++kth;
      printTree(t->right, s, kth, mode);
    }
    else
    {
      printTree(t->left, s, kth, mode);
      printTree(t->right, s, kth, mode);
      s.push(t->element);
      ++kth;
    }
  }

  void printTree(BinaryNode *t, ostream & out, int mode) const
  {
    if (t == nullptr)
    {
      return;
    }

    if (mode == 0)
    {
      // preorder
      out << t->element << endl;
      printTree(t->left, out, mode);
      printTree(t->right, out, mode);
    }
    else if (mode == 1)
    {
      // inorder
      printTree(t->left, out, mode);
      out << t->element << endl;
      printTree(t->right, out, mode);
    }
    else
    {
      printTree(t->left, out, mode);
      printTree(t->right, out, mode);
      out << t->element << endl;
    }
  }

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
