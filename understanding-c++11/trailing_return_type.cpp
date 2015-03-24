#include "trailing_return_type.h"

NS_BEGIN(elloop)
NS_BEGIN(trailing_return_type)

TEST(TrailingReturnType, UsedInTemplate) {
	int i = 10;
	double d = 1.11;
	auto result = sum(i, d);

	EXPECT_EQ(typeid(result).hash_code(), typeid(double).hash_code());
	// or
	bool same = std::is_same<double, decltype(result)>::value;
	EXPECT_TRUE(same);
}

TEST(TrailingReturnType, UsefulTest) {
    /*
    int( *(*pf())() )() {
        return nullptr;
    }
    
    auto pf1() -> auto (*)() -> int(*)() {
        return  nullptr;
    }
    */
	bool same = std::is_same<decltype(pf), decltype(pf1)>::value;
	EXPECT_TRUE(same);

    typedef int( *ptr_f )();
    typedef ptr_f( *t )();
    same = std::is_same<t, decltype(pf())>::value;
    EXPECT_TRUE( same );

    //ptr_f ptrf;
    //t ptr_ptr_f;
    //int( *ptr1 )() = ptrf;
    //int( *(*pptr1)() )() = ptr_ptr_f;
}
NS_END(trailing_return_type)
NS_END(elloop)