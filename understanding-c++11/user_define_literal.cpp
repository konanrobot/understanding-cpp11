#include "user_define_literal.h"
#include "gtest/gtest.h"

NS_ELLOOP_BEGIN

#ifdef _MSC_VER
#else
Person operator "" _person(const char * name, int age) {
    return Person(name, age);
}
#endif


TEST(UserDefineLiteral, Construct) {

}


NS_ELLOOP_END