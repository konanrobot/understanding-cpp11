#ifdef _MSC_VER
#pragma once
#else
_Pragma("once")
#endif
#include "inc.h"

NS_BEGIN(elloop)
NS_BEGIN(trailing_return_type)

// review following sum definition in decltype namespace.
// its fallback is that you must call this function with a third param which
// should be exactly the same type of (t1 + t2).
template<typename T1, typename T2>
void sum(const T1 & t1, const T2 & t2, decltype(t1 + t2) & sum) {
	return (t1 + t2);
}


// this won't work, because t1 and t2 (int decltype(t1+t2)) 
// are unknown symbols before parse params list.
template<typename T1, typename T2>
decltype(t1 + t2) sum2(const T1& t1, const T2 & t2) {
	return t1 + t2;
}

template <typename T1, typename T2>
auto sum(const T1 & t1, const T2 & t2) -> decltype(t1 + t2) {
	return (t1 + t2);
}

// this feature can also used with :
// 1. normal function definition/declaration.
// 2. function pointer definition/declaration.
// 3. struct, union, enum member definiton. 
// 4. todo!

//---------------------- examples ----------------------
// 1. normal function definition.
auto foo() -> int {
	return 1;
}

auto foo2() -> void {}

// 2. function pointer
//a complex function definition.
// pf() defines a function, whose 
// return type A is a function ptr pA( pA = B (*pA)() ),
// pA points to a type B, which is still a function ptr ( B = int (*)() ).
int( *(*pf())() )() {
    return nullptr;
}

// same with:
auto pf1() -> auto (*)() -> int(*)() {
    return  nullptr;
}


int ( *pf2() )() {
    return nullptr;
}


// 3. struct, union, enum. todo!


NS_END(trailing_return_type)
NS_END(elloop)