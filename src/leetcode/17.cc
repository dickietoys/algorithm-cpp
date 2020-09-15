#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    string s;
    vector<string> result;

    s = "23";
    result = letterCombinations(s);
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << endl;
    }
  }

  void Aux(string &digits,
           int pos,
           vector<string> &result,
           string &item,
           map<int, vector<string>> &dict)
  {
    if (pos >= digits.size())
    {
      result.push_back(item);
      return;
    }

    for (int i = 0; i < dict[digits[pos] - '0'].size(); ++i)
    {
      item += dict[digits[pos] - '0'][i];
      Aux(digits, pos + 1, result, item, dict);
      item.pop_back();
    }
  }

  vector<string> letterCombinations(string digits) {
    if (digits == "")
    {
      return {};
    }
    map<int, vector<string>> dict = {
      {2, {"a","b","c"}},
      {3, {"d","e","f"}},
      {4, {"g","h","i"}},
      {5, {"j","k","l"}},
      {6, {"m","n","o"}},
      {7, {"p","q","r","s"}},
      {8, {"t","u","v"}},
      {9, {"w","x","y","z"}}
    };
    vector<string> result;
    string item = "";
    Aux(digits, 0, result, item, dict);

    return result;
  }

};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
