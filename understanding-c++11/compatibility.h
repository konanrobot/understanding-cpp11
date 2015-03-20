#ifdef WIN32
#pragma once
#else
_Pragma("once")
#endif // WIN32

#include "inc.h"
#include "messi.h"

NS_ELLOOP_BEGIN

#ifdef WIN32

#if __cplusplus < 201103L
#endif

#else
#if __cplusplus < 201103L
#error "should use c++11 complier."
#endif 

#endif// WIN32

static_assert(sizeof(int) == 4, "sizeof int should be 4 bytes.");

template <typename T> class Printer;

class Compatibility : public Messi {
    public:
        // using BaseTest::BaseTest(10);
        Compatibility * run() final override;
    private:
    // local init.
    int i_ = 0;
    float f_{1.1};

    // new friend grammer.
    friend Printer<Compatibility>; 
};

// test final keyword.
class Dc : public Compatibility {
  public:
    // Dc * run()  {return this;} // error: run() is final in base-class Compatibility.
};

// total template definiton.
template <typename T>
class Printer {
  public:
    void p(const T & t) {
      pcln("in Printer<T>");
    }
};

// partial sepcialization.
template <>
class Printer<Compatibility> {
  public:
    void p(const Compatibility & t) {
      psln(t.i_);
      psln(t.f_);
    }
  private:
};


NS_ELLOOP_END
