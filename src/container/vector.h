#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

namespace wdq
{
template <typename T>
class Vector
{
 public:
  explicit Vector(int initSize=0)
      : theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)
  {
    objects = new T[theCapacity];
  }
  Vector(const Vector &rhs)
      : objects(nullptr)
  {
    operator=(rhs);
  }
  ~Vector()
  {
    delete []objects;
  }

  const Vector &operator=(const Vector &rhs)
  {
    if (this != &rhs)
    {
      delete []objects;
      theSize = rhs.theSize;
      theCapacity = rhs.theCapacity;
      objects = new T[theCapacity];
      for (int i = 0; i < theSize; ++i)
      {
        objects[i] = rhs.objects[i];
      }
    }

    return *this;
  }

  void reserve(int newCapacity)
  {
    if (newCapacity < theSize)
    {
      return;
    }

    T *oldArray = objects;
    objects = new T[newCapacity];
    for (int i = 0; i < theSize; i++)
    {
      objects[i] = oldArray[i];
    }
    theCapacity = newCapacity;

    delete []oldArray;
  }

  void resize(int newSize)
  {
    if (newSize > theCapacity)
    {
      reserve(newSize * 2 + 1);
    }
    theSize = newSize;
  }

  T &operator[](int index)
  {
    return objects[index];
  }

  const T &operator[](int index) const
  {
    return objects[index];
  }

  bool empty() const
  {
    return theSize == 0;
  }

  void push_back(const T &value)
  {
    if (theSize == theCapacity)
    {
      reserve(theSize * 2 + 1);
    }
    objects[theSize++] = value;
  }

  void pop_back()
  {
    --theSize;
  }

  const T &back() const
  {
    return objects[theSize - 1];
  }

  typedef T *iterator;
  typedef const T *const_iterator;

  iterator begin()
  {
    return &objects[0];
  }

  const_iterator begin() const
  {
    return &objects[0];
  }

  iterator end()
  {
    return &objects[theSize];
  }

  const_iterator end() const
  {
    return &objects[theSize];
  }

  enum {SPARE_CAPACITY = 16};
 private:
  int theSize;
  int theCapacity;
  T *objects;
};

template<class T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &vecData)
{

  for (typename Vector<T>::const_iterator cit = vecData.begin(); cit != vecData.end(); ++cit)
  {
    os << *cit << ", ";
  }

  return os;
}

}

#endif
