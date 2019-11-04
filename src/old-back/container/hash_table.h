#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <vector>
#include <list>
#include <hashtable.h>

using namespace std;

template<class T>
class HashTable
{
 public:
  explicit HashTable(int size = 101)
  {}

  bool contains(const T & x) const
  {
    list<T> whichList = theLists[myhash(x)];
    return find(begin(whichList), end(whichList), x) != end(whichList);
  }

  void makeEmpty()
  {
    for (list<T> &dataList : theLists)
    {
      dataList.clear();
    }
  }

  bool insert(const T & x)
  {
    auto & whichList = theLists[ myhash( x ) ];
    if( find( begin( whichList ), end( whichList ), x ) != end( whichList ) )
      return false;
    whichList.push_back( x );
    if( ++currentSize > theLists.size( ) )
      rehash( );
    return true;
  }

  bool remove(const T & x)
  {
    list<T> whichList = theLists[myhash(x)];
    auto itr = find(begin(whichList), end(whichList), x);
    if (itr == end(whichList))
    {
      return false;
    }

    whichList.erase(itr);
    --currentSize;
    return true;
  }

 private:
  vector<list<T>> theLists;
  int currentSize;

  void rehash()
  {
  }

  size_t myhash(const T & x) const
  {
    size_t hashVal = 0;
    for (char ch : x)
    {
      hashVal = 37 * hashVal + ch;
    }

    return hashVal % theLists.size();
  }
};


#endif
