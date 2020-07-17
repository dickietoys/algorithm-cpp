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
#include <cmath>
#include <queue>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
 public:
  void RunTest()
  {
    // BANC
    string result = minWindow("ADOBECODEBANC", "ABC");
    cout << result << endl;
  }

  string minWindow(string s, string t) {
    int i = 0;
    int j = 0;

    vector<int> distance(2, 0);
    int min = std::numeric_limits<int>::max();
    unordered_map<char, int> hashtable;
    int count = 0;
    for (char c : t)
    {
      hashtable[c] = 1;
    }

    while (j < s.size())
    {
      if (hashtable[s[j]] == 1)
      {
        ++hashtable[s[j]];
        ++count;
      }
      else
      {
        ++j;
      }

      while (count == t.size())
      {
        cout << i << ", " << j << endl;
        if (min > j - i + 1)
        {
          distance[0] = i;
          distance[1] = j;
          min = j - i + 1;
        }

        if (hashtable[s[i]] >= 2)
        {
          --hashtable[s[i]];
          --count;
        }
        ++i;
      }
    }

    if (min != std::numeric_limits<int>::max())
    {
      cout << distance[0] << ", " << distance[1] << endl;
      return s.substr(distance[0], distance[1] - distance[0] + 1);
    }
    else
    {
      return "";
    }
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", " << endl;
    }
    cout << endl;
  }

  template<class T>
  void Show(vector<vector<T>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ", " << endl;
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
