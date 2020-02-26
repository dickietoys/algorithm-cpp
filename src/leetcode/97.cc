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
    int input;
    bool result;

    result = isInterleave("aabcc", "dbbca", "aadbbcbcac");
    cout << "result: " << result << endl;
    assert(result == true);

    result = isInterleave("aabcc", "dbbca", "aadbbbaccc");
    cout << "result: " << result << endl;
    assert(result == false);
  }

  bool isInterleave(string s1, string s2, string s3) {
    map<char, int> m1;
    map<char, int> m2;
    for (char c : s1)
    {
      m1[c] += 1;
    }

    for (char c : s2)
    {
      m2[c] += 1;
    }

    for (auto it : m1)
    {
      cout << it.first << ":" << it.second << endl;
    }

    cout << "==================================" << endl;
    for (auto it : m2)
    {
      cout << it.first << ":" << it.second << endl;
    }

    return Aux(m1, m2, s3, 0, false);
  }

  bool Aux(map<char, int> &m1, map<char, int> &m2, string &s3, int s3Pos, bool chose1)
  {
    bool result = false;
    if (s3Pos >= s3.size())
    {
      cout << "hehehehe" << endl;
      return true;
    }

    if (chose1)
    {
      if (m1[s3[s3Pos]] > 0)
      {
        --m1[s3[s3Pos]];
        result = Aux(m1, m2, s3, s3Pos + 1, false);
        ++m1[s3[s3Pos]];
      }
      else
      {
        cout << "s3Pos: " << s3Pos << ":" << s3[s3Pos] << ":" << chose1 << endl;
        for (auto it : m1)
        {
          cout << it.first << ":" << it.second << endl;
        }

        cout << "==================================" << endl;
        for (auto it : m2)
        {
          cout << it.first << ":" << it.second << endl;
        }
        return false;
      }
    }
    else
    {
      if (m2[s3[s3Pos]] > 0)
      {
        --m2[s3[s3Pos]];
        result = Aux(m1, m2, s3, s3Pos + 1, true);
        ++m2[s3[s3Pos]];
      }
      else
      {
        cout << "s3Pos: " << s3Pos << ":" << s3[s3Pos] << ":" << chose1 << endl;
        for (auto it : m1)
        {
          cout << it.first << ":" << it.second << endl;
        }

        cout << "==================================" << endl;
        for (auto it : m2)
        {
          cout << it.first << ":" << it.second << endl;
        }
        return false;
      }
    }

    return result;
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
