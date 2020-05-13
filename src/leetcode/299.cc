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

class Solution {
 public:
  void RunTest()
  {
  }

  /*
    You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

    Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows.

    Please note that both secret number and friend's guess may contain duplicate digits.

    Example 1:

    Input: secret = "1807", guess = "7810"

    Output: "1A3B"

    Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
    Example 2:

    Input: secret = "1123", guess = "0111"

    Output: "1A1B"

    Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.


    "1123"
    "0111"
    Output
    "0A2B"
    Expected
    "1A1B"
   */
  string getHint(string secret, string guess) {
    int bulls = 0;
    int cows = 0;
    for (int i = 0; i < secret.size(); ++i)
    {
      if (secret[i] == guess[i])
      {
        secret[i] = '*';
        guess[i] = '&';
        ++bulls;
      }
    }

    for (int i = 0; i < secret.size(); ++i)
    {
      for (int j = 0; j < guess.size(); ++j)
      {
        if (secret[i] == guess[j])
        {
          ++cows;
          secret[i] = '*';
          guess[j] = '&';
          break;
        }
      }
    }

    return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
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
        cout << result[i][j] << ", ";
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
