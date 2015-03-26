#ifdef _MSC_VER
#pragma once
#else
_Pragma( "once" )
#endif
#include "inc.h"

NS_BEGIN( elloop )
NS_BEGIN( variadic_template )

// va_arg function in old c++.
// drawback: must specify data type in va_arg.(e.g. va_arg(args, int)).
// i.e. va_arg do not know the type info of the args.
int sum( int count, ... );

// variadic template solve this problem.

// 1. variadic template class
// template <typename...args> class Foo;

// 2. variadic template function
// template <typename ... T> void foo(T ... args);
// restriction: variadic args must be the last param in foo().

// concepts: unpack, pack expansion.
// two kinds of pack expansion: <Args...>, <Args>... .
// e.g. 
/*
// use <Args...>
template <typename ... Args> class Bar;
template <typename ... Args>
class Foo: private Bar<Args...> {};

if Args == X, Y
class Foo will be:
class Foo : private Bar<X, Y> {}

// use <Args>...
template <typename T> class Bar1;
template <typename ... Args>
class Foo1 : private Bar1<Args>... {};

if Args == X, Y;
class Foo1 will be : 
class Foo1 : private Bar1<X>, private Bar1<Y> {}

*/

//--------------------------- begin test ---------------------------

// define a Tuple use type template.

// declaration.
template <typename ... Args> class Tuple;

// partial specialization
template <typename First, typename ... Others>
class Tuple<First, Others...> : private Tuple<Others...> {
public:
    First first;
};

// end of recursive specialization.
template <> class Tuple<> {};



NS_END(variadic_template )
NS_END(elloop )