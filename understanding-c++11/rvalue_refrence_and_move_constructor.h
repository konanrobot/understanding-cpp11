#ifdef _MSC_VER
#pragma once
#else
_Pragma( "once" )
#endif
#include "inc.h"
#include <string>

NS_BEGIN( elloop )
NS_BEGIN( rvalue_refrence_and_move_constructor )

/// copy constructor with pointer.
template <typename T>
class HasPointer {
public:
    HasPointer() : data_(new T(T())) {
        LOGD( "construct %s\n", typeid(*this).name() );
    }
    HasPointer(T* t) {
        if ( t != nullptr ) {
            data_ = ( new T( *t ) );
        }
        else {
            data_ = new T( T() );
        }
    }
    HasPointer( const HasPointer & other ) : data_(new T(*other.data_)){}
    ~HasPointer() {
        delete data_;
    }
    const T & data() const {
        assert( data_ != nullptr );
        return *data_;
    }
private:
    T * data_;
};

class Dog {
public:
    Dog(const char * name = nullptr ) : name_(name == nullptr ? "" : name) { }
    std::string name_;
};


NS_END(rvalue_refrence_and_move_constructor )
NS_END(elloop )