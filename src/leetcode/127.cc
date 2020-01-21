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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    int result = ladderLength("hit", "cog", wordList);
    cout << result << endl;
  }

  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    deque<string> dq;
    unordered_set<string> bookmark;
    dq.push_back(beginWord);
    int counter = 1;
    while (!dq.empty())
    {
      int size = dq.size();
      while (size)
      {
        string data = dq.front();
        dq.pop_front();
        if (data == endWord)
        {
          return counter;
        }
        for (int i = 0; i < wordList.size(); ++i)
        {
          if (Valid(data, wordList[i]) && bookmark.count(wordList[i]) == 0)
          {
            bookmark.insert(wordList[i]);
            dq.push_back(wordList[i]);
          }
        }
        --size;
      }
      ++counter;
    }

    return 0;
  }

  bool Valid(string &src, string &dst)
  {
    int count = 0;
    for (int i = 0; i < src.size(); ++i)
    {
      if (src[i] != dst[i])
      {
        ++count;
      }
    }

    return count == 1 ? true : false;
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
