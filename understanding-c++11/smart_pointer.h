#ifdef _MSC_VER
#pragma once
#else
_Pragma( "once" )
#endif
#include "inc.h"
#include <memory>

NS_BEGIN( elloop )
NS_BEGIN( smart_pointer )

// old smart pointer auto_ptr<T> is depreciated.

// In cpp11, 
// 1. unique_ptr<T> substitutes auto_ptr<T>.
// it only supports move assignment.(copy constructor and copy assignment is deleted).
// does not support pointer arithmetics.
// see http://www.cplusplus.com/reference/memory/unique_ptr/?kw=unique_ptr for
// more information about unique_ptr<T>.

// 2. shared_ptr<T> is used in count reference

// 3. weak_ptr<T> is used to test validity of shared_ptr<T>.

// they are included in header <memory>.

//--------------------------- begin test ---------------------------

// following using declarations are aim at typing less. 
template <typename T>
using u_ptr = std::unique_ptr<T>;

template <typename T>
using s_ptr = std::shared_ptr<T>;

template <typename T>
using w_ptr = std::weak_ptr<T>;

class Dog {
public:
    Dog(const char * name) : name_(name) {
        p( "dog " );
        p( name_ );
        pln( " comes" );
    }
    ~Dog() {
        p( "dog " );
        p( name_ );
        pln( " is gone" );
    }
    const std::string & name() const {
        return name_; 
    }
private:
    std::string name_;
};

std::ostream& operator << (std::ostream & os, const Dog & dog) {
    os << dog.name();
    return os;
}


NS_END(smart_pointer )
NS_END(elloop )
