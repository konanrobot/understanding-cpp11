#ifdef _MSC_VER
#pragma once
#else
_Pragma("once")
#endif
#include "inc.h"
#include <map>
NS_ELLOOP_BEGIN

// using �����������ͣ����ܱ�typedef����ǿ�󣬳���typedef��������һ�㹦������
//��using��ģ�����и�����


template<typename T>
using IntMap = std::map<T, int>;

NS_ELLOOP_END