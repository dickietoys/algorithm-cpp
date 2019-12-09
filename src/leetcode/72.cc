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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    string input;
    int result;

    result = minDistance("horse", "ros");
    cout << "result: " << result << endl;
    assert(result == 3);

    result = minDistance("intention", "execution");
    cout << "result: " << result << endl;
    assert(result == 5);
  }

  int minDistance(string word1, string word2) {
    if (word1 == "")
    {
      return word2.size();
    }
    if (word2 == "")
    {
      return word1.size();
    }

    vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), 0));
    if (word1[0] != word2[0])
    {
      dp[0][0] = 1;
    }

    for (int i = 1; i < word1.size(); ++i)
    {
      if (word1[i] == word2[0])
      {
        dp[i][0] = i;
      }
      else
      {
        dp[i][0] = dp[i-1][0] + 1;
      }
    }

    for (int i = 1; i < word2.size(); ++i)
    {
      if (word1[0] == word2[i])
      {
        dp[0][i] = i;
      }
      else
      {
        dp[0][i] = dp[0][i-1] + 1;
      }
    }

    for (int i = 1; i < word1.size(); ++i)
    {
      for (int j = 1; j < word2.size(); ++j)
      {
        if (word1[i] == word2[j])
        {
          dp[i][j] = dp[i - 1][j - 1];
        }
        else
        {
          dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }
      }
    }

    return dp[word1.size() - 1][word2.size() - 1];
  }

  void Show(vector<int> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
  }

  void Show(vector<vector<int>> &result)
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
