#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>
#include <deque>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    vector<int> result = findSubstring(s, words);
    result = findSubstring(s, words);
    Show(result);
  }


  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    Aux(s, 0, 0, words, 0);

    return result;
  }

  void Aux(string s, int leftPos, int rightPos, vector<string>& words, int index)
  {
    for (size_t = i)
  }

  void Show(vector<int> result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
    }

    cout << endl;
  }

};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
