#ifdef WIN32
#pragma once
#else
_Pragma("once")
#endif // WIN32

#include "inc.h"
#include "messi.h"

NS_ELLOOP_BEGIN

class ThreadTest : public Messi {
  public:
    ThreadTest * run() override;
    void testWithCpp11();
    void testWithPthread();
    void testAtomic();
};

NS_ELLOOP_END
