#ifdef _MSC_VER
#pragma once
#else
_Pragma("once")
#endif
#include "inc.h"

NS_BEGIN(elloop)
NS_BEGIN(decltype_test)

// used for testing typedid.hash_code.
class TypeA {};
class TypeB {};

// testing anonymous struct type.
struct { int a; } a_struct_value;

// testing using decltype in template function.
template <typename T1, typename T2>
void Sum2(T1 & t1, T2 &t2, decltype(t1 + t2) & s) {
	s = t1 + t2;
}

// Notice when using decltype.
// 4-rules: decltype(e)
// 1. ���e��
//      1) �ǲ������ŵı�Ƿ�(id-expression)����
//      2) ���Ա���ʱ��ʽ
//    ��ôdecltype(e)�����;���e�����͡�
// 2. �������e��һ������ֵ(xvalue), ����ΪT����ôdecltype(e)����ΪT&&.
// 3. �������e��һ����ֵ, ��ôdecltype(e)ΪT&.
// 4. �������������decltype(e)ΪT.
// see TEST(Decltype, FourRulesForUsingDecltype) in decltype.cpp.

NS_END(decltype_test)
NS_END(elloop)