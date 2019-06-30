#ifndef LIST_H_
#define LIST_H_

namespace wdq
{
template<class T>
class List
{
 private:
  struct Node
  {
    T data;
    Node *prev;
    Node *next;

    Node(const T &t = T(), Node *p = nullptr, Node *n = nullptr)
        : data(t), prev(p), next(n)
    {}
  };

 public:
  class const_iterator
  {
   public:
    const_iterator() : current(nullptr)
    {}

    const T & operator*() const
    {
      return retrieve();
    }

    const_iterator & operator++()
    {
      current = current->next;
      return *this;
    }

    const_iterator operator++(int)
    {
      const_iterator old = *this;
      ++(*this);
      return old;
    }

    bool operator==(const const_iterator &rhs) const
    {
      return current == rhs.current;
    }

    bool operator!=(const const_iterator &rhs) const
    {
      return !(*this == rhs);
    }

   protected:
    Node *current;

    T & retrieve() const
    {
      return current->data;
    }

    const_iterator(Node *p)
        : current(p)
    {}
  };

  class iterator : public const_iterator
  {
   public:
    iterator()
    {}

    T & operator*()
    {}

    const T & operator*() const
    {

    }

    iterator & operator++()
    {}

    iterator operator++(int)
    {}

   protected:
    iterator(Node *p) :
        const_iterator(p)
    {}

  };

 public:
  List()
  {}
  List(const List&rhs)
  {}
  ~List()
  {}
  const List &operator=(const List &rhs)
  {}

  iterator begin()
  {
    return iterator(head->next);
  }

  const_iterator begin() const
  {
    return const_iterator(head->next);
  }

  iterator end()
  {
    return iterator(tail);
  }

  const_iterator end() const
  {
    return const_iterator(tail);
  }

  int size() const
  {
    return theSize;
  }

  bool empty() const
  {
    return size() == 0;
  }

  T & front()
  {
    return *begin();
  }

  const T & front() const
  {
    return *begin();
  }

  T & back()
  {
    return *--end();
  }

  T & back() const
  {
    return *--end();
  }

  void push_front(const T &t)
  {
    insert(begin(), t);
  }

  void push_back(const T &t)
  {
    insert(end(), t);
  }

  void pop_front()
  {
    erase(begin());
  }
  void pop_back()
  {
    erase(--end());
  }

  iterator insert(iterator itr, const T &t)
  {
  }

  iterator erase(iterator itr)
  {}

  iterator erase(iterator start, iterator end)
  {}



  void clear()
  {
    while (!empty())
    {
      pop_front();
    }
  }

 private:
  int theSize;
  Node *head;
  Node *tail;

  void init()
  {}
};


}


#endif
