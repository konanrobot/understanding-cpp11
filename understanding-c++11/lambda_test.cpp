#include "lambda_test.h"

NS_ELLOOP_BEGIN

LambdaTest* elloop::LambdaTest::run()
{
	simple1();
	return this;
}


void LambdaTest::simple1()
{
	int a(3);
	int b(4);
	auto total = [](int x, int y) -> int { return x + y;  };
	psln(total(a, b));

}

NS_ELLOOP_END