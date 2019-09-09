#ifndef DYNAMIC_ALGO_H_
#define DYNAMIC_ALGO_H_

#include <vector>
#include <iostream>
#include <cstdio>

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


#endif
