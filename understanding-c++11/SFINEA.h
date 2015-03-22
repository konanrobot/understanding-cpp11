#ifdef _MSC_VER
#pragma once
#else
_Pragma( "once" )
#endif
#include "inc.h"

NS_ELLOOP_BEGIN

namespace sfinea {

// SFINEA : substitution failure is not an error.
// ������Ʊ��㷺����STL�С�
// ���ֳ�����Ч���Ǻܷ��ϳ���Ա��Ԥ��ġ�

class Foo {
public:
    typedef int inside_type;
};

template<typename T>
void f( typename T::inside_type) {
    psln( "f(T::inside_type)" );
}

template<typename T>
void f( T ) {
    pln( "f(T)" );
}

}

NS_ELLOOP_END