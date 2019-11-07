#ifndef WORD_BREAK_H_
#define WORD_BREAK_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

#include <testsuit/TestBase.h>

using namespace std;

/*
  切钢条
*/
class WordBreak : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================WordBreak====================" << endl;
    map<string, bool> dict = {
      {"mobile", true},
      {"samsung", true},
      {"sam", true},
      {"sung", true},
      {"man", true},
      {"mango", true},
      {"icecream", true},
      {"and", true},
      {"go", true},
      {"i", true},
      {"like", true},
      {"ice", true},
      {"cream", true},
    };

    string input = "ilike";
    // result yes
    cout << "BruteResult: " << BruteResult(dict, input) << endl;
    cout << "DpResult: " << DpResult(dict, input) << endl;

    input = "ilikesamsung";
    // result yes
    cout << "BruteResult: " << BruteResult(dict, input) << endl;
    cout << "DpResult: " << DpResult(dict, input) << endl;

    input = "iiiiiiii";
    // result yes
    cout << "BruteResult: " << BruteResult(dict, input) << endl;
    cout << "DpResult: " << DpResult(dict, input) << endl;

    input = "";
    // result yes
    cout << "BruteResult: " << BruteResult(dict, input) << endl;
    cout << "DpResult: " << DpResult(dict, input) << endl;

    input = "ilikelikeimangoiii";
    // result yes
    cout << "BruteResult: " << BruteResult(dict, input) << endl;
    cout << "DpResult: " << DpResult(dict, input) << endl;

    input = "samsungandmango";
    // result yes
    cout << "BruteResult: " << BruteResult(dict, input) << endl;
    cout << "DpResult: " << DpResult(dict, input) << endl;

    input = "samsungandmangok";
    // result yes
    cout << "BruteResult: " << BruteResult(dict, input) << endl;
    cout << "DpResult: " << DpResult(dict, input) << endl;
    cout << "=================WordBreak====================" << endl;
  }

  bool BruteResult(const map<string, bool> &dict, const string &input)
  {
    return BruteResultAux(dict, input);
  }

  bool DpResult(const map<string, bool> &dict, const string &input)
  {
    return DpResultAux(dict, input);
  }

 private:
  bool BruteResultAux(const map<string, bool> &dict, const string &input)
  {
    if (input.size() == 0)
    {
      return true;
    }

    bool has = false;
    for (size_t i = 1; i <= input.size(); ++i)
    {
      if (dict.find(input.substr(0, i)) != dict.cend())
      {
        has = BruteResultAux(dict, input.substr(i, input.size()));
      }
    }

    return has;
  }

  bool DpResultAux(const map<string, bool> &dict, const string &input)
  {
    vector<vector<int>> bookmark(input.size(), vector<int>(input.size(), false));

    for (size_t i = 0; i < input.size(); i++)
    {
      for (size_t j = 1; j <= i; ++j)
      {
        string leftString = input.substr(i, j);
        string rightString = input.substr(i+j, input.size());
        if (dict.find(leftString) != dict.cend())
        {
          if (rightString.size() == 0)
          {
            bookmark[i][j] = true;
          }
          else
          {
            bookmark[i][j] = bookmark[input.size()-j][input.size()];
          }
        }
        else
        {
          bookmark[i][j] = false;
        }
      }
    }

    return bookmark[0][input.size()];
  }

  void showBookmark(const vector<vector<int>> &bookmark)
  {
    cout << endl;
    for (size_t i = 0; i < bookmark.size(); ++i)
    {
      for (size_t j = 0; j < bookmark[i].size(); ++j)
      {
        cout << bookmark[i][j] << ", ";
      }
      cout << endl;
    }
  }
};

#endif
