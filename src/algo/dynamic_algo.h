#ifndef DYNAMIC_ALGO_H_
#define DYNAMIC_ALGO_H_

#include <vector>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class CutSteelBar
{
 public:
  CutSteelBar(vector<int> &barLenPriceInit) :
      barLenPrice_(barLenPriceInit),
      maxPrice_(0)
  { }

  int calcByTopDown(int length)
  {
    cutStrategy_.assign(length+1, 0);
    priceBookMark_.assign(length+1, 0);
    steelBarLength_ = length;
    maxPrice_ = calcByTopDownAux(length);

    return maxPrice_;
  }

  void showCutStrategy()
  {
    cout << steelBarLength_ <<" size cut strategy: ";
    int length = steelBarLength_;
    while (length > 0)
    {
      cout << cutStrategy_[length] << ", ";
      length = length - cutStrategy_[length];
    }

    cout << endl;
  }

  int calcByBottomUp(int length)
  {
    cutStrategy_.assign(length+1, 0);
    priceBookMark_.assign(length+1, 0);
    steelBarLength_ = length;
    maxPrice_ = calcByBottomUpAux(length);

    return maxPrice_;
  }

 private:
  int calcByTopDownAux(int length)
  {
    if (length == 0)
    {
      return 0;
    }

    if (priceBookMark_[length] != 0)
    {
      return priceBookMark_[length];
    }

    int currentMaxPrice = 0;
    for (int i = 1; i <= length; ++i)
    {
      int currentPrice = barLenPrice_[i] + calcByTopDownAux(length - i);
      if (currentMaxPrice < currentPrice)
      {
        currentMaxPrice = currentPrice;
        cutStrategy_[length] = i;
      }
    }

    priceBookMark_[length] = currentMaxPrice;

    return currentMaxPrice;
  }

  int calcByBottomUpAux(int length)
  {
    for (int i = 1; i <= length; ++i)
    {
      int currentMaxPrice = 0;
      for (int j = 1; j <= i; ++j)
      {
        int currentPrice = barLenPrice_[j] + priceBookMark_[j-i];
        if (currentMaxPrice < currentPrice)
        {
          currentMaxPrice = currentMaxPrice;
          cutStrategy_[i] = j;
        }
        priceBookMark_[i] = currentMaxPrice;
      }
    }

    return priceBookMark_[length];
  }

 private:
  vector<int> barLenPrice_;
  vector<int> cutStrategy_;
  int maxPrice_;
  vector<int> priceBookMark_;
  int steelBarLength_;
};

class LCS
{
 public:
  string FindLCS(const string &s1, const string &s2)
  {
    vector<vector<int>> bookmark(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    vector<vector<string>> path(s1.size() + 1, vector<string>(s2.size() + 1, ""));
    for (int i = 1; i <= s1.size(); ++i)
    {
      for (int j = 1; j <= s2.size(); ++j)
      {
        if (s1[i - 1] == s2[j - 1])
        {
          bookmark[i][j] = bookmark[i - 1][j - 1] + 1;
          path[i][j] = "found";
        }
        else
        {
          if (bookmark[i - 1][j] > bookmark[i][j - 1])
          {
            bookmark[i][j] = bookmark[i - 1][j];
            path[i][j] = "up";
          }
          else
          {
            bookmark[i][j] = bookmark[i][j - 1];
            path[i][j] = "left";
          }
        }
      }
    }

    string lcs;
    printPath(path, s1, s1.size(), s2.size(), lcs);

    return lcs;
  }

  string bruteFind(const string &s1, const string &s2)
  {
    vector<string> buffer;
    for (int i = s1.size() - 1; i >= 0; --i)
    {
      findAllSubSequence(s1, i, buffer);
    }

    string *pLCS = nullptr;
    size_t currentMaxLCSsize = 0;
    for (string &s : buffer)
    {
      size_t i = 0;
      size_t j = 0;
      while (i < s.size() && j < s2.size())
      {
        if (s[i] == s2[j])
        {
          ++i;
          ++j;
        }
        else
        {
          ++j;
        }
      }

      if (i == s.size() && currentMaxLCSsize < s.size())
      {
        currentMaxLCSsize = s.size();
        pLCS = &s;
      }
    }

    return *pLCS;
  }

 private:
  void printPath(vector<vector<string>> &path, const string &s, int i, int j, string &lcs)
  {
    if (i == 0 or j == 0)
    {
      return;
    }
    if (path[i][j] == "found")
    {
      printPath(path, s, i - 1, j - 1, lcs);
      lcs.push_back(s[i - 1]);
    }
    else if (path[i][j] == "left")
    {
      printPath(path, s, i, j - 1, lcs);
    }
    else
    {
      printPath(path, s, i - 1, j, lcs);
    }
  }

  void findAllSubSequence(const string &s, int startPos, vector<string> &buffer)
  {
    int ori_size = buffer.size();
    for (int i = 0; i < ori_size; ++i)
    {
      string currentStr = string(1, s[startPos]).append(buffer[i]);
      buffer.push_back(currentStr);
    }
    buffer.push_back(string(1, s[startPos]));
  }
};


#endif
