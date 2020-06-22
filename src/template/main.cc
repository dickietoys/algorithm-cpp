#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <iterator>
#include <set>
#include <cmath>
#include <queue>
#include <list>

using namespace std;


class Solution {
 public:
  void RunTest()
  {
    cout << "==================bruteforce======================" << endl;
    vector<string> dict = {"mobile","samsung","sam","sung",
                           "man","mango","icecream","and",
                           "go","i","like","ice","cream"};
    // true
    bool result = WordBreakProblemRecur(dict,
                                        "ilikesamsung");
    cout << "WordBreakProblemRecur: " << result << endl;
    // true
    result = WordBreakProblemRecur(dict,
                                   "iiiiiiii");
    cout << "WordBreakProblemRecur: " << result << endl;
    // true
    result = WordBreakProblemRecur(dict,
                                   "");
    cout << "WordBreakProblemRecur: " << result << endl;
    // true
    result = WordBreakProblemRecur(dict,
                                   "ilikelikeimangoiii");
    cout << "WordBreakProblemRecur: " << result << endl;
    // true
    result = WordBreakProblemRecur(dict,
                                   "samsungandmango");
    cout << "WordBreakProblemRecur: " << result << endl;
    // false
    result = WordBreakProblemRecur(dict,
                                   "samsungandmangok");
    cout << "WordBreakProblemRecur: " << result << endl;
    cout << "==================dp======================" << endl;
    result = WordBreakProblemDp(dict,
                                "ilikesamsung");
    cout << "WordBreakProblemDp: " << result << endl;
    result = WordBreakProblemDp(dict,
                                "iiiiiiii");
    cout << "WordBreakProblemDp: " << result << endl;
    result = WordBreakProblemDp(dict,
                                "");
    cout << "WordBreakProblemDp: " << result << endl;
    result = WordBreakProblemDp(dict,
                                "ilikelikeimangoiii");
    cout << "WordBreakProblemDp: " << result << endl;
    result = WordBreakProblemDp(dict,
                                "samsungandmango");
    cout << "WordBreakProblemDp: " << result << endl;
    result = WordBreakProblemDp(dict,
                                "samsungandmangok");
    cout << "WordBreakProblemDp: " << result << endl;
  }


  bool WordBreakProblemRecurAux(vector<string> dict, string &s, int pos)
  {
    if (pos >= s.size())
    {
      return true;
    }

    for (int i = 0; i < dict.size(); ++i)
    {
      string &item = dict[i];
      if (s.substr(pos, item.size()) == item)
      {
        return WordBreakProblemRecurAux(dict, s, pos + item.size());
      }
    }

    return false;
  }

  bool WordBreakProblemRecur(vector<string> dict, string s)
  {
    return WordBreakProblemRecurAux(dict, s, 0);
  }

  bool WordBreakProblemDp(vector<string> dict, string s)
  {
    return false;
  }

  template<class T>
  void Show(const vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
    }
    cout << endl;
  }

  template<class T>
  void Show(const vector<vector<T>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ", ";
      }
      cout << endl;
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
