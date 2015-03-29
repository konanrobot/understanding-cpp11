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

    // �ܲ�����һ��ͬһ�������ʼ��ͬһ������ ���磬ͬһ��Dog
    // Ҳ����˵����copy constructor���Ƿ�Ҫ�ж������ҹ���
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