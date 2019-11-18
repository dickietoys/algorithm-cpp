#ifndef REVERSE_STRING_H
#define REVERSE_STRING_H

#include <iostream>
#include <testsuit/TestBase.h>

using namespace std;

class ReverseString : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================ReverseString====================" << endl;
    string str = "a,b$c";
    cout << "before reverse: " << str << endl;
    Reverse(str);
    cout << "after reverse: " << str << endl;

    str = "Ab,c,de!$";
    cout << "before reverse: " << str << endl;
    Reverse(str);
    cout << "after reverse: " << str << endl;

    str = "a!!!b.c.d,e'f,ghi";
    cout << "before reverse: " << str << endl;
    Reverse(str);
    cout << "after reverse: " << str << endl;

    str = "abcdefg";
    cout << "before reverse: " << str << endl;
    Reverse(str);
    cout << "after reverse: " << str << endl;
    cout << "=================ReverseString====================" << endl;
  }

  void Reverse(string &str)
  {
    int i = 0;
    int j = str.size() - 1;
    while (i < j)
    {
      if (!IsAlphabet(str[i]))
      {
        ++i;
        continue;
      }

      if (!IsAlphabet(str[j]))
      {
        --j;
        continue;
      }

      std::swap(str[i], str[j]);
      ++i;
      --j;
    }
  }

 private:
  bool IsAlphabet(char &c)
  {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
      return true;
    }
    else
    {
      return false;
    }
  }

};

#endif
