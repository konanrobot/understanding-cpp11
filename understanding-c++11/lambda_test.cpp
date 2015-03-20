#include "lambda_test.h"

NS_ELLOOP_BEGIN

LambdaTest* elloop::LambdaTest::run()
{
	//simple1();
	simpleUsingCapture();
	return this;
}


void LambdaTest::simple1()
{
	int a(3);
	int b(4);
	auto total = [](int x, int y) -> int { return x + y;  };
	psln(total(a, b));

}

void LambdaTest::simpleUsingCapture()
{
	int a(3);
	int b(4);
	psln(b);
	auto total = [a, &b]() -> int { b = 10;  return a + b; };
	psln(b);
	psln(total());
	b = 10;
	psln(b);
	psln(total());
}

NS_ELLOOP_END