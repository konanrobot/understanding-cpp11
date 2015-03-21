#include "lambda_test.h"
#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric> // accumulate

NS_ELLOOP_BEGIN

TEST(Lambda, Simple) {
    int a(3), b(4);
    auto sum = [](int x, int y) -> int { return x + y;  };
    EXPECT_EQ(7, sum(a, b));
}

TEST(Lambda, SimpleUsingCapture) {
    int a(3);
    int b(4);
    int c(5);

    // capture only a and b.
    auto sum1 = [a, b]() -> int { return a + b;  };

    // capture all.
    auto sum2 = [=]() -> int { return a + b + c;  };

    EXPECT_EQ(7, sum1());
    EXPECT_EQ(12, sum2());
}

TEST(Lambda, CaptureByVlaueNotice) {
    int val(10);
    auto by_value = [val]() {return val; };
    EXPECT_EQ(10, by_value());

    // ������lambda������ʱ�򣬰�ֵ��׽�ı����൱�ڱ�����һ�����գ�����������һɲ��.
    // Ҳ����˵������by_value��ʱ���val��ֵ�������ˡ�

    val = 100;
    EXPECT_EQ(10, by_value());

}

TEST(Lambda, CaptureByReference) {
    int a(1);
    auto change_a = [&a]() {a = 10; };
    change_a();
    EXPECT_EQ(10, a);

    int b(0);
    auto try_to_change_a_by_value = [&, a]() mutable {
        // when define this lambda, like take a snapshot of a, and a inside
        // is act as a local var.
        a = 11;     
        //psln(a);
        b = a;
        //psln(b);
    };
    try_to_change_a_by_value();
    EXPECT_EQ(10, a);   // a won't change.
    EXPECT_EQ(11, b);
}

TEST(Lambda, CompareWithFunctor) {
    DoubleFunctor double_func;
    int x(2);
    int square_x1 = double_func(x);
    int square_x2 = [x]() -> int {return 2 * x; }();
    EXPECT_EQ(square_x1, square_x2);
    EXPECT_EQ(4, square_x2);
}

TEST(Lambda, InitConstVarUseLambda) {
    int val(10);
    //p("input a integer:");
    //std::cin >> val;

    const int x = [](int n){
        return n * n;
    }(val);
    EXPECT_EQ(100, x);
}

// lambda����ת���ɺ���ָ�룬����ͬʱ������������������
// 1. lambdaû�в����κα������� [];
// 2. ����ָ��ĺ���ԭ�ͱ����lambda�ĵ��÷�ʽ��ȫһ��;
// ����ָ���޷�ת����lambda.
TEST(Lambda, ConvertLambdaToFunctionPointer) {
    auto lambda_sum2 = [](int a, int b)->int {return a + b; };
    auto lambda_sum2_capture = [=](int a, int b)->int {return a + b; };

    typedef int (*Sum2ptr)(int x, int y);
    typedef int (*Sum1ptr)(int x);

    Sum2ptr sum2 = lambda_sum2;
    //Sum2ptr sum22 = lambda_sum2_capture; // error: capture is not allowed.
    //Sum1ptr sum1 = lambda_sum2; // error: different params count .

    decltype(lambda_sum2) lambda_sum2_copy = lambda_sum2;
    //decltype(lambda_sum2) lambda_sum2_copy2 = sum2; // error: cannot convert.
}

//=================== Work With STL =====================
// find a number in vector.
TEST(Lambda, WorkWithSTLFindANumber) {
    USING_NS_STD;
    vector<int> nums { 1, 2, 3, 4, 5, 6, 7, 8 };
    int target(10);
    // find using functor.
    auto iter = std::find_if(
        nums.begin(), nums.end(), bind2nd(equal_to<int>(), target));
    EXPECT_TRUE(iter == nums.end()); // find nothing.

    // find using lambda.
    auto iter2 = find_if(
        nums.begin(), nums.end(), [=](int i) { return i == target; });
    EXPECT_TRUE(iter2 == nums.end()); // find nothing.
}

TEST(Lambda, DoManyThingsAtTheSameTime) {
    USING_NS_STD;
    vector<int> nums({ 1, 2, 3 });
    int increase(0);
    int decrease(10);
    // use STL numeric, loop 2 times.
    increase = accumulate(nums.begin(), nums.end(), increase);
    decrease = accumulate(nums.begin(), nums.end(), decrease, minus<int>());
    EXPECT_EQ(6, increase);
    EXPECT_EQ(4, decrease);

    increase = 0;
    decrease = 10;
    // use lambda. loop 1 time.
    for_each(nums.begin(), nums.end(), [&](int i) {
        increase += i;
        decrease -= i;
    });
    EXPECT_EQ(6, increase);
    EXPECT_EQ(4, decrease);
}

int global_int;
// lambda�ľ����ԣ����ܲ�����������Զ�������
TEST(Lambda, LimitationOfLambda) {
    // error: �޷���lambda�в�����о�̬�洢����ʱ��ı���
    //auto can_capture_or_not = [global_int] {}; 

    class FunctorCanCaptureEverything {
    public:
        FunctorCanCaptureEverything(int data) : data_(data) {}
        int operator() () {
            return data_;
        }
    private:
        int data_;
    };
    FunctorCanCaptureEverything func(global_int);
    EXPECT_EQ(global_int, func());
}

NS_ELLOOP_END  