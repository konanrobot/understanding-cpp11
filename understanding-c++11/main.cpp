#include "compatibility.h"
#include "thread_test.h"
#include "constructor_test.h"
#include "pod_test.h"
#include "initializer_test.h"
#include "lambda_test.h"
#include "gtest/gtest.h"

USING_NS_ELLOOP;

#define ELLOOP_TEST(x) do { delete (new (x))->run(); } while (0);
int main(int argc, char** argv) {

    // use gtest.
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

	//ELLOOP_TEST(LambdaTest);

	//ELLOOP_TEST(PodTest);

	// InitializerTest it({1, 2, 3});

	// ELLOOP_TEST(InitializerTest);
	// ELLOOP_TEST(ConstructorTest);

	// ELLOOP_TEST(ThreadTest);

	// ELLOOP_TEST(Compatibility);

	//return 0;
}
