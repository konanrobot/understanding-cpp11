#ifdef WIN32
#pragma once
#else
_Pragma("once")
#endif // WIN32

#include "messi.h"

NS_ELLOOP_BEGIN

class LambdaTest : public Messi
{
public:
	virtual LambdaTest* run() override;

	void simple1();
};


NS_ELLOOP_END