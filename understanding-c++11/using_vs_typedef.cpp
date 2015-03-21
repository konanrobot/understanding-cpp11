#include "using_vs_typedef.h"
#include "gtest/gtest.h"

NS_ELLOOP_BEGIN

USING_NS_STD;
TEST(Using, TemplateUsing) {
    vector<int> vi{ 1, 2, 3 };
    vector<int>::iterator iter;
    bool same = is_same<VecIter<int>, decltype(iter)>::value;
    EXPECT_TRUE(same);
}

NS_ELLOOP_END