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

	// try to use unique_ptr in stl container.
	/*std::vector<u_ptr<Dog>> ptr_vec;
	ptr_vec.push_back(pd1);				// fail, copy constructor is deleted.
	ptr_vec.push_back(pd2);*/


}
TEST(SmartPointer, SharedPointer) {
	// shared_ptr 放到容器里，引用计数加1，那么容器销毁他会自动减1吗？
	s_ptr<int> p1;
	p1 = new int(10);
}

NS_END( smart_pointer )
NS_END( elloop )