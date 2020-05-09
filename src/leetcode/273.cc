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
    private final String[] LESS_THAN_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    private final String[] TENS = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    private final String[] THOUSANDS = {"", "Thousand", "Million", "Billion"};

    public String numberToWords(int num) {
        if (num == 0) return "Zero";

        int i = 0;
        String words = "";

        while (num > 0) {
            if (num % 1000 != 0)
                words = helper(num % 1000) +THOUSANDS[i] + " " + words;
            num /= 1000;
            i++;
        }

        return words.trim();
    }

    private String helper(int num) {
        if (num == 0)
            return "";
        else if (num < 20)
            return LESS_THAN_20[num] + " ";
        else if (num < 100)
            return TENS[num / 10] + " " + helper(num % 10);
        else
            return LESS_THAN_20[num / 100] + " Hundred " + helper(num % 100);
    }

   */

  const vector<string> k_less_than_20= {"",
                                        "One",
                                        "Two",
                                        "Three",
                                        "Four",
                                        "Five",
                                        "Six",
                                        "Seven",
                                        "Eight",
                                        "Nine",
                                        "Ten",
                                        "Eleven",
                                        "Twelve",
                                        "Thirteen",
                                        "Fourteen",
                                        "Fifteen",
                                        "Sixteen",
                                        "Seventeen",
                                        "Eighteen",
                                        "Nineteen"};
  const vector<string> k_tens = {"",
                                 "Ten",
                                 "Twenty",
                                 "Thirty",
                                 "Forty",
                                 "Fifty",
                                 "Sixty",
                                 "Seventy",
                                 "Eighty",
                                 "Ninety"};
  const vector<string> k_thousands = {"", "Thousand", "Million", "Billion"};

  string trim(string s)
  {
    size_t start = s.find_first_not_of(' ');
    size_t stop = s.find_last_not_of(' ');
    s = s.substr(start, stop - start + 1);

    return s;
  }

  string numberToWords(int num) {
    if (num == 0)
      return "Zero";

    int i = 0;
    string words = "";

    while (num > 0)
    {
      if (num % 1000 != 0)
      {
        words = helper(num % 1000) + k_thousands[i] + " " + words;
      }
      num = num / 1000;
      ++i;
    }
    return trim(words);
  }

  string helper(int num) {
    if (num == 0)
    {
      return "";
    }
    else if (num < 20)
    {
      return k_less_than_20[num] + " ";
    }
    else if (num < 100)
    {
      return k_tens[num / 10] + " " + helper(num % 10);
    }
    else
    {
      return k_less_than_20[num / 100] + " Hundred " + helper(num % 100);
    }
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
