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
    vector<string> arr;
    string result;

    arr = {"flower","flow","flight"};
    result = longestCommonPrefix(arr);
    cout << "result: " << result << endl;
    assert(result == "fl");

    arr = {"dog","racecar","car"};
    result = longestCommonPrefix(arr);
    cout << "result: " << result << endl;
    assert(result == "");
  }

  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0)
    {
      return "";
    }

    string result = "";
    for (size_t i = 0; i < strs[0].size(); ++i)
    {
      bool allMatch = true;
      for (size_t j = 1; j < strs.size(); ++j)
      {
        if (i < strs[j].size())
        {
          if (strs[j][i] != strs[0][i])
          {
            allMatch = false;
            break;
          }
        }
        else
        {
          allMatch = false;
          break;
        }
      }
      if (allMatch)
      {
        result.push_back(strs[0][i]);
      }
      else
      {
        break;
      }
    }

    return result;
  }

};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
