#ifdef _MSC_VER
#pragma once
#else
_Pragma("once")
#endif
#include "inc.h"

NS_BEGIN(elloop)
NS_BEGIN(strongly_typed_enum)

//fallbackk of old enum: (��ǿ����������)
// 1. namespace pollution, enum's value auto inject into global namespace.
// 2. convert to int implicitly.
// 3. ռ�ÿռ䲻ȷ��

// new enum in cpp11.
// 1. use class keyword
// 2. a base_type is optional, which specifies the type used in enum.

using base_type = int;
//using base_type = unsigned int;
//using base_type = wchar_t; //should cause a error, but passes in vs2013.
enum class kAnimal : base_type { Dog=-111, Cat };

// without base_type, default is int.
enum class kCar { Jeep, Tank};


NS_END(strongly_typed_enum)
NS_END(elloop)