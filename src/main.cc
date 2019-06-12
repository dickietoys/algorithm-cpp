#include <container/vector.h>

#include <iostream>

int main()
{
  wdq::Vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);
  std::cout << v << std::endl;


  return 0;
}
