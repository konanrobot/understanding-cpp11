#include "rvalue_refrence_and_move_constructor.h"
NS_BEGIN( elloop )
NS_BEGIN( rvalue_refrence_and_move_constructor )

TEST( RValueReference, CopyConstructorWithPointer ) {
    pcln( "RValueReference TEST" );

    HasPointer<int> a;
    HasPointer<int> b( a );
    EXPECT_EQ( 0, a.data() );
    EXPECT_EQ( a.data(), b.data() );

    pcln( "another test" );
    HasPointer<HasPointer<HasPointer<HasPointer<HasPointer<int>>>>> hh;
    EXPECT_EQ( 0, hh.data().data().data().data().data() );

    pcln( "another test" );
    auto jim = new Dog( "jim" );
    HasPointer<Dog> hj( jim );
    psln( hj.data().name_ );

    // 能不能用一个同一个对象初始化同一个对象？ 比如，同一个Dog
    // 也就是说，在copy constructor中是否要判断是自我构造
    // Dog * dog;
    // new (dog)Dog();
    //Dog * dd;
    //new (*dd)(dd);
    //new (&dd)Dog();
    //psln( dd->name_ );

    int * ip = new int(int());
    delete ip;
    Dog d;

}


NS_END( rvalue_refrence_and_move_constructor )
NS_END( elloop )