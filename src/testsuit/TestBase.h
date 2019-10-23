#ifndef TEST_BASE_H_
#define TEST_BASE_H_

class TestBase{
 public:
  virtual void DoTest() = 0;
  virtual ~TestBase()
  {}
};

#endif
