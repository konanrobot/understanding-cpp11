// memory leak check.
#ifdef _MSC_VER && _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
// with detail description of memory leak.
#define new new( _CLIENT_BLOCK, __FILE__, __LINE__)
void turnOnMemroyCheck() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}
#endif
#include "inc.h"
#include "gtest/gtest.h"

USING_NS_ELLOOP;


void dummyExitFunction() {
	int i(0);
}

int main(int argc, char** argv) {

#ifdef _MSC_VER && _DEBUG
	// make program stop when debug.
	atexit(dummyExitFunction);

	turnOnMemroyCheck();
#endif

	// use gtest.
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
