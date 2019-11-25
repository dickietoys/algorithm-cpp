#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    cout << "=========================MinPartition=========================" << endl;
    unordered_map<string, bool> dictionary = {{"mobile", true}, {"samsung", true}, {"sam", true},
                                              {"sung", true}, {"man", true}, {"mango", true},
                                              {"icecream", true}, {"and", true}, {"go", true},
                                              {"i", true}, {"like", true}, {"ice", true}, {"cream", true} };
    string s = "ilikesamsung";
    int result = BruteResult(dictionary, s);
    cout << "BruteResult: " << result << endl;
    result = DpResult(dictionary, s);
    cout << "DpResult: " << result << endl;

    s = "iiiiiiii";
    result = BruteResult(dictionary, s);
    cout << "BruteResult: " << result << endl;
    result = DpResult(dictionary, s);
    cout << "DpResult: " << result << endl;

    s = "";
    result = BruteResult(dictionary, s);
    cout << "BruteResult: " << result << endl;
    result = DpResult(dictionary, s);
    cout << "DpResult: " << result << endl;

    s = "ilikelikeimangoiii";
    result = BruteResult(dictionary, s);
    cout << "BruteResult: " << result << endl;
    result = DpResult(dictionary, s);
    cout << "DpResult: " << result << endl;

    s = "samsungandmango";
    result = BruteResult(dictionary, s);
    cout << "BruteResult: " << result << endl;
    result = DpResult(dictionary, s);
    cout << "DpResult: " << result << endl;

    s = "samsungandmangok";
    result = BruteResult(dictionary, s);
    cout << "BruteResult: " << result << endl;
    result = DpResult(dictionary, s);
    cout << "DpResult: " << result << endl;
    cout << "=========================MinPartition=========================" << endl;
  }

  int DpResult(unordered_map<string, bool> &dictionary, string &str)
  {
    vector<int> bookmark(str.size() + 1);
    bookmark[0] = 1;
    for (size_t i = 1; i <= str.size(); ++i)
    {
      for (size_t j = 1; j <= i; ++j)
      {
        bookmark[i] |= bookmark[i-j] && dictionary[str.substr(i-j, j)];
      }
    }

    return bookmark[str.size()];
  }

  int BruteResult(unordered_map<string, bool> &dictionary, string &str)
  {
    return BruteResultAux(dictionary, str, 0);
  }

  int BruteResultAux(unordered_map<string, bool> &dictionary, string &str, int strPos)
  {
    int length = str.size();
    if (strPos >= length)
    {
      return 1;
    }

    for (int i = 1; i <= length - strPos; ++i)
    {
      if (dictionary[str.substr(strPos, i)])
      {
        if (BruteResultAux(dictionary, str, strPos + i) == 1)
        {
          return 1;
        }
      }
    }

    return 0;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
