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
  class const_iterator
  {
   public:
    const_iterator() : current(nullptr)
    {}
   protected:
    Node *current;
  };
  class iterator : public const_iterator{};

};

struct Node{

};



}


#endif
