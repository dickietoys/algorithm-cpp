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
    int num;
    string result;

    num = 3;
    result = intToRoman(num);
    cout << "result: " << result << endl;
    assert(result == "III");

    num = 4;
    result = intToRoman(num);
    cout << "result: " << result << endl;
    assert(result == "IV");

    num = 9;
    result = intToRoman(num);
    cout << "result: " << result << endl;
    assert(result == "IX");

    num = 58;
    result = intToRoman(num);
    cout << "result: " << result << endl;
    assert(result == "LVIII");
  }

  string intToRoman(int num) {
    map<int, string> dict = {
      {1, "I"},
      {5, "V"},
      {10, "X"},
      {50, "L"},
      {100, "C"},
      {500, "D"},
      {1000, "M"},
    };

    vector<int> unit = {1000, 500, 100, 50, 10, 5, 1};
    int unitSize = unit.size();
    string result = "";
    for (int i = 0; i < unitSize; i += 2)
    {
      int count = num / unit[i];
      if (count < 4)
      {
        for (int j = 0; j < count; ++j)
        {
          result.append(dict[unit[i]]);
        }
      }
      else if (count == 4)
      {
        result.append(dict[unit[i]]);
        result.append(dict[unit[i-1]]);
      }
      else if (count >=5 && count <= 8)
      {
        result.append(dict[unit[i-1]]);
        for (int j = 0; j < count - 5; ++j)
        {
          result.append(dict[unit[i]]);
        }
      }
      else if (count == 9)
      {
        result.append(dict[unit[i]]);
        result.append(dict[unit[i-2]]);
      }

      num = num % unit[i];
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
