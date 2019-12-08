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
    string result;

    input = "/home/";
    result = simplifyPath(input);
    cout << "result: " << result << endl;
    assert(result == "/home");

    input = "/../";
    result = simplifyPath(input);
    cout << "result: " << result << endl;
    assert(result == "/");

    input = "/home//foo/";
    result = simplifyPath(input);
    cout << "result: " << result << endl;
    assert(result == "/home/foo");

    input = "/a/./b/../../c/";
    result = simplifyPath(input);
    cout << "result: " << result << endl;
    assert(result == "/c");
  }

  string simplifyPath(string path) {
    string res;
    string tmp;
    vector<string> st;
    stringstream ss(path);
    while (getline(ss, tmp, '/'))
    {
      if (tmp == "" || tmp == ".")
      {
        continue;
      }
      if (tmp == ".." && !st.empty())
      {
        st.pop_back();
      }
      else if (tmp != "..")
      {
        st.push_back(tmp);
      }
    }

    for (auto str : st)
    {
      res += "/" + str;
    }

    return res.empty() ? "/" : res;
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
