#ifdef WIN32
#pragma once
#else
_Pragma("once")
#endif // WIN32

#include "inc.h"

NS_ELLOOP_BEGIN

class Messi {
  public:
    virtual ~Messi() {
      pcln("deleting a test.");
    }

    Messi() {
      pcln("creating a test.");
    }

    // BaseTest(int id) : id_(id) {
    //   pcln("creating a test.");
    // }

    virtual Messi * run() = 0;
  private:
    int id_;
};

NS_ELLOOP_END
