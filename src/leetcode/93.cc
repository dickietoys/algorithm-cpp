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
#include <bitset>

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    string input;
    vector<string> result;

    input = "0000";
    result = restoreIpAddresses(input);
    Show(result);
  }

  vector<string> restoreIpAddresses(string s)
  {
    vector<string> result;
    int sSize = s.size();
    for (int i = 1; i <= 3 && i <= sSize - 3; ++i)
    {
      for (int j = 1; j <= 3 && i + j <= sSize - 2; ++j)
      {
        for (int k = 1; k <= 3 && i+ j +k <= sSize - 1; ++k)
        {
          string s1 = s.substr(0, i);
          string s2 = s.substr(0 + i, j);
          string s3 = s.substr(0 + i + j, k);
          string s4 = s.substr(0 + i + j + k);
          if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4))
          {
            result.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
          }
        }
      }
    }

    return result;
  }

  bool isValid(string &s)
  {
    if (s.size() > 3 || s.size() == 0 || (s[0] == '0' && s.size() > 1) || std::stoi(s) > 255)
    {
      return false;
    }

    return true;
  }


  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
    }
    cout << endl;
  }

  template<class T>
  void Show(vector<vector<T>> &result)
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
