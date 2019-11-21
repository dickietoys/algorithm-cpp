#ifndef STRING_WORD_DICT_H
#define STRING_WORD_DICT_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <map>

using namespace std;

class StringWordDict : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================StringWordDict====================" << endl;
    map<int, string> dict = {};
    for (int i = 1; i <= 26; ++i)
    {
      dict.insert({i, std::to_string(char('a' + i - 1))});
    }

    string str = "123";
    DoMap(dict, str);

    cout << "=================StringWordDict====================" << endl;
  }

  void DoMap(map<int, string> &dict, string &str)
  {
    string buffer;
    DoMapAux(dict, str, 0, buffer);
  }

  void DoMapAux(map<int, string> &dict, string &str, int pos, string buffer)
  {
    int length = str.size();
    if (pos >= length)
    {
      cout << buffer << endl;
      return;
    }

    for (int j = 1; j < length - pos + 1; ++j)
    {
      string curBuffer = buffer;
      curBuffer.append(str.substr(pos, j)).append(", ");
      // cout << pos << ":" << j << "; curBuffer: " << curBuffer << endl;
      DoMapAux(dict, str, pos+j, curBuffer);
    }
  }
};

#endif
