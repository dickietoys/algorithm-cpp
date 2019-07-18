#ifndef LIST_H_
#define LIST_H_

#include <iostream>

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
    friend class List<T>;
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
    friend class List<T>;
    iterator()
    {}
    iterator & operator++()
    {
      this->current = this->current->next;
      return *this;
    }

    iterator operator++(int)
    {
      iterator old = *this;
      ++(*this);
      return old;
    }

   protected:
    iterator(Node *p) :
        const_iterator(p)
    {}

  };

 public:
  List()
  {
    init();
  }

  List(const List&rhs)
  {
    init();
    for(auto &x : rhs)
    {
      push_back(x);
    }
  }

  ~List()
  {
    clear();
    delete head;
    delete tail;
  }

  const List &operator=(const List &rhs)
  {
    List copy = rhs;
    std::swap(*this, copy);
    return *this;
  }

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
    Node *p = itr.current;
    theSize++;
    return { p->prev = p->prev->next = new Node{ t, p->prev, p } };
  }

  iterator erase(iterator itr)
  {
    Node *p = itr.current;
    iterator retVal{ p->next };
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    theSize--;
    return retVal;
  }

  iterator erase(iterator from, iterator to)
  {
    for( iterator itr = from; itr != to; )
      itr = erase( itr );
    return to;
  }

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
  {
    theSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
  }
};


#endif
