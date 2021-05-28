#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    cout << "=========================MinPartition=========================" << endl;
    string s = "ABC";
    BruteResult(s);
    cout << "=========================MinPartition=========================" << endl;
  }

  void BruteResult(string &s)
  {
    BruteResultAux(s, "");
  }

  void BruteResultAux(string &s, string buffer)
  {
    if (s.size() == 0)
    {
      cout << buffer << endl;
      return;
    }

    for (size_t i = 0; i < s.size(); ++i)
    {
      string tmpS = s;
      tmpS.erase(i);
      string tmpBuffer = buffer;
      tmpBuffer.push_back(s[i]);
      BruteResultAux(tmpS.erase(i), buffer);
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
