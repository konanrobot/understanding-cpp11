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

TEST( Decltype, FourRulesForUsingDecltype ) {
    int i( 10 );
    int arr[10];
    int *ptr = arr;
    struct S { int si; } s;
    void foo(double);
    void foo( int );
    int && rvalueReference();
    const bool func( int );

    bool same( false );

    //------------------------------------------------------
    //1. e is id-expression(without brackets) or member visit operator. --> decltype(e) == T.
    decltype(arr) v1;   // int[10]
    same = std::is_same<decltype(v1), int[10]>::value;
    EXPECT_TRUE( same );

    decltype(ptr) v2;   // int*
    same = std::is_same<decltype(v2), int*>::value;
    EXPECT_TRUE( same );

    decltype(s.si) v3;  // int
    same = std::is_same<decltype(v3), int>::value;
    EXPECT_TRUE( same );

    //decltype(foo) v4; // error: foo is overloaded.
    //------------------------------------------------------

    //------------------------------------------------------
    // 2. e == xvalue --> decltype(e) == rvalue-reference.
    decltype(rvalueReference) v5;   // int&&
    same = std::is_same<decltype(v5), int&&>::value;
    EXPECT_TRUE( same );
    //------------------------------------------------------
    
    //------------------------------------------------------
    // 3. e --> lvalue --> decltype(e)==lvalue-reference.
    // following var must be bound with i, because they are all l-value-reference.
    decltype(true ? i : i) v6 = i;      // int&
    same = std::is_same<decltype(v6), int&>::value;
    EXPECT_TRUE( same );

    decltype((i)) v7 = i;             // int&
    same = std::is_same<decltype(v7), int&>::value;
    EXPECT_TRUE( same );

    decltype(++i) v8 = i;             // int&
    same = std::is_same<decltype(v8), int&>::value;
    EXPECT_TRUE( same );

    decltype(arr[0]) v9 = i;          // int&, operator[] return l-value
    same = std::is_same<decltype(v9), int&>::value;
    EXPECT_TRUE( same );

    decltype("hello") v10 = "12345";  // const char (&v10) [5];
    same = std::is_same<decltype(v10), const char (&)[5]>::value;
    EXPECT_TRUE( same );

    decltype(*ptr) v11 = i;           // int&, operator* return l-value
    same = std::is_same<decltype(v11), int&>::value;
    EXPECT_TRUE( same );
    //------------------------------------------------------


    //------------------------------------------------------
    // 4. other situations, e --> decltype(e) == e.
    decltype(1) v12;                  // int
    same = std::is_same<decltype(v12), int>::value;
    EXPECT_TRUE( same );

    decltype(i++) v13;                // int
    same = std::is_same<decltype(v13), int>::value;
    EXPECT_TRUE( same );

    decltype(func( 1 )) v14 = 1000;   // const bool
    same = std::is_same<decltype(v14), const bool>::value;
    EXPECT_TRUE( same );
    //------------------------------------------------------
}


NS_END(decltype_test)
NS_END(elloop)