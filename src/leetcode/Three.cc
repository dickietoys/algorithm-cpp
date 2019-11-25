#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>

using namespace std;

class Solution {
public:
  void RunTest()
  {

  }

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
  {
    int size1 = nums1.size();
    int size2 = nums2.size();
    bool isEven = (size1 + size2) % 2 == 0 ? true : false;
    int middle = size1 + size2;

    while (true)
    {
      int middle1 = size1 / 2;
      int middle2 = size2 / 2;

      if (nums1[middle1] > nums[middle2])
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
