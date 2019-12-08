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
    vector<string> input;
    vector<string> result;

    input = {"This", "is", "an", "example", "of", "text", "justification."};
    result = fullJustify(input, 16);
    Show(result);

    input = {"What","must","be","acknowledgment","shall","be"};
    result = fullJustify(input, 16);
    Show(result);

    input = {"Science","is","what","we","understand","well","enough","to","explain",
             "to","a","computer.","Art","is","everything","else","we","do"};
    result = fullJustify(input, 20);
    Show(result);
  }

  vector<string> fullJustify(vector<string>& words, int maxWidth) {

  }

  void Show(vector<string> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
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
