#include "decltype.h"

NS_BEGIN(elloop)
NS_BEGIN(decltype_test)

TEST(Decltype, TypeId) {
	// typeid requires RTTI mechanism.
	// to turn it off, use -fno-rttion in GCC, use /GR- in _MSC.
	TypeA a;
	TypeB b;
	TypeA c;
	psln(typeid(a).name());
	psln(typeid(b).name());

	auto a_hash_code = typeid(a).hash_code();
	auto b_hash_code = typeid(b).hash_code();
	auto c_hash_code = typeid(c).hash_code();
	psln(typeid(a_hash_code).name()); // size_t
	EXPECT_EQ(a_hash_code, c_hash_code);
	EXPECT_NE(b_hash_code, c_hash_code);
}

TEST(Decltype, UsedInStandard) {
	// examples of using decltype in cpp11 standard.
	//using size_t = decltype(sizeof(0));
	//using ptrdiff_t = decltype((int*)0 - (int*)0);
	//using nullptr_t = decltype(nullptr);

	// result_of<T> template is implemented base on decltype.
	typedef int(*func)(int, int);
	//std::result_of<func>::type f2;  // error:
	std::result_of<func(int,int)>::type f2;
	//psln(typeid(f2).name());  // int
	bool same = std::is_same<decltype(f2), int>::value;
	EXPECT_TRUE(same);

	EXPECT_EQ(typeid(int).hash_code(), typeid(f2).hash_code());
	
}

TEST(Decltype, ReuseAnonymouseType) {
	// a_struct_value is a value of anonymouse struct type.
	decltype(a_struct_value) another;
	another.a = 100;
	EXPECT_EQ(100, another.a);
}

TEST(Decltype, TemplateFunction) {
	int i(10);
	double d(1.2);
	double sumid(0);
	// restriction: sumid's type must be (i + d)'s type: double.
	Sum2(i, d, sumid);
	EXPECT_EQ(11.2, sumid);
}

NS_END(decltype_test)
NS_END(elloop)