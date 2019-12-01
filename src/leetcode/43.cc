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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<int> input;
    string result;

    result = multiply("2", "3");
    cout << "result: " << result << endl;

    result = multiply("123", "456");
    cout << "result: " << result << endl;
  }

  string multiply(string num1, string num2) {
    int size1 = num1.size();
    int size2 = num2.size();
    vector<int> digitVec(size1+size2, 0);

    int numIndex1 = 0;
    int numIndex2 = 0;
    for (int i = size1 - 1; i >= 0; ++i)
    {
      int remain = 0;
      numIndex2 = 0;
      int numValue1 = char2int(num1[i]);
      for (int j = size2 - 2; j >= 0; ++j)
      {
        int numValue2 = char2int(num2[j]);
        int digitValue = numValue1 * numValue2 + digitVec[numIndex1 + numIndex2] + remain;
        remain = digitValue / 10;
        digitVec[numIndex1 + numIndex2] = digitValue % 10;
        ++numIndex2;
      }
      if (remain > 0)
      {
        digitVec[numIndex1 + numIndex2] += remain;
      }
      ++numIndex1;
    }

    int pos = digitVec.size() - 1;
    while (pos >= 0 && digitVec[pos] == 0)
    {
      --pos;
    }

    string result = "";

    while (pos >= 0)
    {
      result.append(std::to_string(digitVec[pos--]));
    }

    return result;
  }

  int char2int(char c)
  {
    return c - '0';
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
