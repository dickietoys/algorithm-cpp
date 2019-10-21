#ifndef GREEDY_ALGO_H_
#define GREEDY_ALGO_H_

#include <vector>

using namespace std;
namespace greedy_algo{

class Activity{
 public:
  int startTime;
  int stopTime;

  Activity():
      startTime(0),
      stopTime(0)
  {}

  Activity(int begin, int end):
      startTime(begin),
      stopTime(end)
  {}
};

class GreedyActivitySelector
{
 public:
  GreedyActivitySelector()
  {}

  GreedyActivitySelector(const vector<Activity> &activities):
      activities_(activities)
  {}

  vector<Activity> FindMaxActivitiesSet(int startTime, int stopTime)
  {
    vector<Activity> selected;
    for (int i = 0; i < activities_.size(); ++i)
    {
      // Activity &activity =
    }

    return selected;
  }

 private:
  vector<Activity> activities_;
};

}

#endif
