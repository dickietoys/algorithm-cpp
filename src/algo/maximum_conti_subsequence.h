#ifndef MAXIMUM_CONTI_SUBSEQUENCE_H_
#define MAXIMUM_CONTI_SUBSEQUENCE_H_

#include <vector>
using namespace std;

class FindMaxSubSequence
{
 public:
  int findMax(vector<int> &data)
  {
    return findMaxRec(data, 0, data.size() - 1);
  }

 private:
  int findMaxRec(vector<int> &data, int left, int right)
  {
    if (left == right)
    {
      if (data[left] > 0)
      {
        return data[left];
      }
      else
      {
        return 0;
      }
    }

    int center = (left + right) / 2;
    int maxLeftSum = findMaxRec(data, left, center);
    int maxRightSum = findMaxRec(data, left, center);

    int leftBorderSum = 0;
    int maxLeftBorderSum = 0;
    for (int i = center; i >= left; --i)
    {
      leftBorderSum += data[i];
      if (leftBorderSum > maxLeftBorderSum)
      {
        maxLeftBorderSum = leftBorderSum;
      }
    }

    int rightBorderSum = 0;
    int maxRightBorderSum = 0;
    for (int i = center + 1; i <= right; ++i)
    {
      rightBorderSum += data[i];
      if (rightBorderSum > maxRightBorderSum)
      {
        maxRightBorderSum = rightBorderSum;
      }
    }

    int maxBorderSum = maxLeftBorderSum + maxRightBorderSum;

    if (maxLeftSum >= maxBorderSum && maxLeftSum >= maxRightSum)
    {
      return maxLeftSum;
    }
    else if(maxRightSum >= maxBorderSum && maxRightSum >= maxLeftSum)
    {
      return maxRightSum;
    }
    else
    {
      return maxBorderSum;
    }
  }
};


#endif
