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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<string> input;
    vector<vector<string>> result;

    input = {
      "eat", "tea", "tan", "ate", "nat", "bat"
    };

    result = groupAnagrams(input);
    Show(result);
  }

  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> storage;
    for (auto it = strs.begin(); it != strs.end(); ++it)
    {
      string ori = *it;
      std::sort(it->begin(), it->end());
      storage[*it].push_back(ori);
    }

    vector<vector<string>> result;
    for (auto it = storage.begin(); it != storage.end(); ++it)
    {
      result.push_back(it->second);
    }

    return result;
  }

  void Show(vector<vector<string>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ",";
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
