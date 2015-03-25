#include "smart_pointer.h"

NS_BEGIN( elloop )
NS_BEGIN( smart_pointer )

// NOTICE!!
// in following codes:
// u_ptr<T> =  std::unique_ptr<T>
// s_ptr<T> = std::shared_ptr<T>
// w_ptr<T> = std::weak_ptr<T>

TEST( SmartPointer, UniquePointer ) {

    u_ptr<int> p { new int( 10 ) };
    EXPECT_EQ( 10, *p );

    u_ptr<int> q( new int( 10 ) );
    EXPECT_EQ( 10, *q );
    
    u_ptr<Dog> pd1( new Dog("tom") );

    //u_ptr<Dog> pd2 = pd1;             // error: copy assignment is deleted.
    u_ptr<Dog> pd2 = std::move(pd1);    // use move assignment.
    EXPECT_EQ( nullptr, pd1 );
    EXPECT_NE( nullptr, pd2 );
    pd2.reset();
    EXPECT_EQ( nullptr, pd2 );
    //*pd1 = Dog( "tom2" );               // error: pd1 is empty(reseted).



}

NS_END( smart_pointer )
NS_END( elloop )