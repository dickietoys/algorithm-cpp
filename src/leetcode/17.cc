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

  vector<string> letterCombinations(string digits)
  {
    vector<string> buffer;
    if (digits == "")
    {
      return buffer;
    }
    map<int, vector<string>> dict = {
      {2, {"a","b","c"}}, {3, {"d","e","f"}},
      {4, {"g","h","i"}}, {5, {"j","k","l"}}, {6, {"m","n","o"}},
      {7, {"p","q","r","s"}}, {8, {"t","u","v"}}, {9, {"w","x","y","z"}}};
    int length = digits.size();

    Aux(digits, 0, dict, buffer, "");
    return buffer;
  }

  void Aux(string &digits,
           int digitPos,
           map<int, vector<string>> &dict,
           vector<string> &buffer,
           string s)
  {
    if (digitPos >= digits.size())
    {
      buffer.push_back(s);
      return;
    }

    int num = digits[digitPos] - '0';
    vector<string> words = dict[num];
    for (size_t i = 0; i < words.size(); ++i)
    {
      string tmp = s;
      tmp.append(words[i]);
      Aux(digits, digitPos+1, dict, buffer, tmp);
    }
  }

};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
