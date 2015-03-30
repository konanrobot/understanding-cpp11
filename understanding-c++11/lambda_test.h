#ifdef _MSC_VER
#pragma once
#else
_Pragma("once")
#endif // _MSC_VER

#include "inc.h"
NS_BEGIN(elloop)
NS_BEGIN(lambda_test)

/*
lambda formula:
[capture](param) [mutable] ->return_type { body; }

1. capture can be following:
    =: capture all variables by value in scope.
    &: capture all variables by reference in father scope.
    this: capture this by value.
    &this: capture this by reference.
    empty: capture nothing.
    examples: 
    [=, &a, &b]: ���÷�ʽ����a,b, �������б�����ֵ���ݡ�
    [&, a, b]: ��ֵ��ʽ����a,b, �������б��������ô��ݡ�
    [=, a]: ���󣬲��ܴ����ظ���������=�Ѿ������˰�ֵ��ʽ����a��
2. param
    like normal function params, can be empty meaning no params.
3. [mutable]
    values in the capture list is const in default.
    if you want to change values in captures list, you should specified the [mutable].
    if mutable specified, the capture values can be modified in <body>.
    if you use mutable, you can't omit param list even if it's empty.
4. -> return_type
    can omit if the <body> doesn't return a value.
    can omit if compiler can deduce its return type.
5. body
    normal function body.

the simplest lambda function can be : []{};

lambda�ľ����ԣ� ���ܲ�����������Զ�������
lambdaע�����
1. �����ɱ�����ʹ��by_value�ķ�ʽ���������ʱ�򣬻����copy������
2. by_reference���ݵ�ʱ����Ȼû��copy������
   ���Ǵ�ʱlambda�븸���������������С�Ĵ������߹�ϵ��
   �����ǵ����ڶദ�޸ĸñ����Ĵ����ʱ��
*/

// util function use by unit test.
class DoubleFunctor {
public:
    int operator() (int x) {
        return 2 * x;
    }
};

NS_END(lambda_test)
NS_END(elloop)
