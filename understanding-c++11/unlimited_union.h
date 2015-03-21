#ifdef _MSC_VER
#pragma once
#else
_Pragma("once")
#endif
#include "inc.h"

NS_ELLOOP_BEGIN

// union in cpp11: allow members which is not pod.
// 

struct NonPod {
    NonPod() {

    }
};

struct Pod {};

union ContainNonPod {
    Pod p;
    //NonPod np;  // error in vs2013 !!! not standard cpp11 compiler.
    int id;
    char name[10];
};

//union ContainString {
    //std::string s;

//};

// annonymous union. p.109




class UnlimitedUnionTest {
public:
};

NS_ELLOOP_END