#ifndef LIST_H_
#define LIST_H_

namespace wdq
{
template<class T>
class List
{
 private:
  struct Node;

 public:
  class const_iterator;
  class iterator;

 public:
  List();

};

template<class T>
struct List<T>::Node{
  T data;

};

template<class T>
class List<T>::const_iterator
{
 public:
  const_iterator() : current(nullptr)
  {}
 protected:
  Node *current;
};

template<class T>
class List<T>::iterator : public List<T>::const_iterator
{
};

}


#endif
