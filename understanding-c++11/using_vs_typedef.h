#ifdef _MSC_VER
#pragma once
#else
_Pragma("once")
#endif
#include "inc.h"
#include <vector>

NS_ELLOOP_BEGIN

// using �����������ͣ����ܱ�typedef����ǿ�󣬳���typedef��������һ�㹦������
//��using��ģ�����и�����

template<typename T> using VecIter = std::vector<T>::iterator;

NS_ELLOOP_END