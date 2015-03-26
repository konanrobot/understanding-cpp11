#include "variadic_template.h"
#include <stdarg.h> // for va_start, va_end, va_arg

NS_BEGIN( elloop )
NS_BEGIN( variadic_template )

// va_arg samples. in old c++ codes.
int sum( int count, ... ) {
    int result( 0 );
    va_list params;
    va_start( params, count );
    for ( int i = 0; i < count; ++i ) {
        result += va_arg( params, int );
    }
    va_end( params );
    return result;
}

TEST( VariadicTemplate, OldVa_arg ) {
    EXPECT_EQ( 5, sum( 2, 1, 4 ) );
    EXPECT_EQ( 10, sum( 3, 1, 4, 5 ) );
    EXPECT_EQ( 75, sum( 15, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5) );
}

TEST( VariadicTemplate, TupleTest ) {

    Tuple<int> t1;
    t1.first;

    Tuple<double, int> t2;
    //psln( (double)t2.first );

    Tuple<int, float, double, int> t;
    //t.head;
}

TEST( VariadicTemplate, TemplateClass ) {
}

NS_END( variadic_template )
NS_END( elloop )
