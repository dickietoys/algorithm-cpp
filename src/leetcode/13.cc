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
    int result;

    s = "III";
    result = romanToInt(s);
    cout << "result: " << result << endl;
    assert(result == 3);

    s = "IV";
    result = romanToInt(s);
    cout << "result: " << result << endl;
    assert(result == 4);

    s = "IX";
    result = romanToInt(s);
    cout << "result: " << result << endl;
    assert(result == 9);

    s = "LVIII";
    result = romanToInt(s);
    cout << "result: " << result << endl;
    assert(result == 58);

    s = "MCMXCIV";
    result = romanToInt(s);
    cout << "result: " << result << endl;
    assert(result == 1994);
  }

  int romanToInt(string s) {
    map<char, int> dict = {
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000},
    };

    int length = s.size();
    int result = 0;
    for (int i = 0; i < length; ++i)
    {
      int curValue = dict[s[i]];
      if (i + 1 < length)
      {
        int nextValue = dict[s[i+1]];
        if (nextValue > curValue)
        {
          result = nextValue + result - curValue;
          ++i;
        }
        else
        {
          result += curValue;
        }
      }
      else
      {
        result += curValue;
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
