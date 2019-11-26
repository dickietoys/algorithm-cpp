#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    string s = "PAYPALISHIRING";
    int n = 3;
    string result = "";
    result = convert(s, n);
    cout << "result: " << result << endl;
    assert(result == "PAHNAPLSIIGYIR");

    n = 4;
    result = convert(s, n);
    cout << "result: " << result << endl;
    assert(result == "PINALSIGYAHRPI");
  }

  string convert(string s, int numRows) {
    if (s == "")
    {
      return "";
    }

    if (numRows == 1)
    {
      return s;
    }

    vector<string> buffer(numRows, "");
    int currentRow = 0;
    bool down = true;
    for (size_t i = 0; i < s.size(); ++i)
    {
      buffer[currentRow].push_back(s[i]);
      if (currentRow == numRows - 1)
      {
        down = false;
      }

      if (currentRow == 0)
      {
        down = true;
      }

      down ? ++currentRow : --currentRow;
    }

    string result = "";
    for (size_t i = 0; i < buffer.size(); ++i)
    {
      result.append(buffer[i]);
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
