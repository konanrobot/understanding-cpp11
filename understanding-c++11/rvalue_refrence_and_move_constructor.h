#ifdef _MSC_VER
#pragma once
#else
_Pragma( "once" )
#endif
#include "inc.h"
#include <memory>
#include <string>

NS_BEGIN( elloop )
NS_BEGIN( rvalue_refrence_and_move_constructor )

// ------------------ Three Kinds of Values in cpp11 ------------------
// 1. lvalue
// 2. rvalue(pure rvalue)
// 3. xvalue(expiring value)
//		2 and 3 are called rvale.
// ���������ֵ��lvalue������ֵ����������ֵrvalue�ͽ���ֵxvalue��
// 1. �ܷ��ڡ�=����ߵ�����ֵ���ұߵ�����ֵ
// 2. ��ȡ��ַ&��������ֵ����������ֵ

// ------------------ useful template to judge l-r value reference ------------------
// 1. is_rvalue_reference
// 2. is_lvalue_reference

// -------------- useful template to judge move ctr(constructor) --------------
// 1. is_move_constructible
// 2. is_trivially_move_constructible
// 3. is_nothrow_move_constructible
// trivial move ctr is like the trivial copy ctr. only bitwise operation.

// ------------------ 2 functions of rvalue_reference ------------------
// 1. implement move semantics. (move ctr, std::move)
// 2. perfect forwards. (std::forward)

// ------------------ reference folding(�����۵�) ------------------
// example:
// typedef int& T;
// T& t;	// in cpp03 is an error; valid in cpp11.
/*
| declare of T | declare of t |  true type of t |
-------------------------------------------------
| X&           |   X          |    X&           |
| X&           |   X&         |    X&           |
| X&           |   X&&        |    X&           |
| X&&          |   X          |    X&&          |
| X&&          |   X&         |    X&           |
| X&&          |   X&&        |    X&&           |
-------------------------------------------------
*/

// ------------------ other useful things ------------------
// 1. move_if_noexcept, performs as move semantics only if the move ctr has noexcept.
//	  otherwise, it performs as copy semantics.
// 2. a high performance swap operation use std::move
template <typename T>
void swap(T&a, T&b) {
	T tmp(std::move(a));
	a = std::move(b);
	b = std::move(tmp);
}

//======================= begin of test =======================

// ------------------ old cpp ------------------
// ͨ��ʹ��const T &�ķ�ʽ���Σ��Ա��ⲻ��Ҫ�Ŀ������졣
/// copy constructor with pointer.
// deep copying the pointer. 
template <typename T>
class HasPointer {
public:
#ifdef _MSC_VER
	HasPointer() _NOEXCEPT : data_(new T(T()))  {
		LOGD("construct %s\n", typeid(*this).name());
	}

	HasPointer(T* ptr) _NOEXCEPT : data_(new T(*ptr))  {
		LOGD("construct %s\n", typeid(*this).name());
	}
#else
	HasPointer() noexcept : data_(new T(T()))  {
		LOGD("construct %s\n", typeid(*this).name());
	}

	HasPointer(T* ptr) noexcept : data_(new T(*ptr))  {
		LOGD("construct %s\n", typeid(*this).name());
	}
#endif

	// copy constructor.
    HasPointer( const HasPointer & other ) : data_(new T(*other.data_)) {
		pln("copy constructor of HasPointer");
	}

	// disable assignment operator.
	HasPointer& operator = (const HasPointer & other) = delete;

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

// ------------------ use move constructor with huge memeory objects ------------------
// ���д������ݵĶ����ڴ�����ʱ�����ʱ��Ӧ���ṩ�ƶ����캯�����������ܡ�
class BigDog
{
public:
	BigDog() {
		LOGD("ctr called: %d\n", ++ctr);
		knowledge_ = new char[kKnowledgeCount];
	}

	BigDog(const BigDog & other) : knowledge_(new char[kKnowledgeCount]) {
		LOGD("cptr called: %d\n", ++cptr);
		memcpy(knowledge_, other.knowledge_, kKnowledgeCount);
	}

	~BigDog() {
		LOGD("dtr called: %d\n", ++dtr);
		delete knowledge_;
	}

	// move constructor.
	BigDog(BigDog&& other) : knowledge_(other.knowledge_) {
		LOGD("mctr called: %d\n", ++mtr);
		other.knowledge_ = nullptr;
	}
	static int dtr;
	static int ctr;
	static int cptr;
	static int mtr;
	static const int kKnowledgeCount = 1000000;
	char *knowledge_;
};

// 
BigDog getTempBigDog();




// ------------------ a good example of using rvalue_reference ------------------
class HugeMem
{
public:
	HugeMem(int size) : size_(size > 0 ? size : 1) {
		data_ = new int[size_];
	}

	HugeMem(HugeMem&& h) : size_(h.size_), data_(h.data_) {
		h.data_ = nullptr;
	}

	int *data_;
	int size_;
};

class Movable
{
public:
	Movable() : i_(new int(0)), hm_(1024) {}


	Movable(Movable && m) :
		i_(m.i_),
		hm_(std::move(m.hm_))		// notice: explicit call HugeMem's move ctr.
	{
		m.i_ = nullptr;
	}

	~Movable(){
		delete i_;
	}
	int * i_;
	HugeMem hm_;
};

Movable getTempMovable();

// ------------------ perfect forward ------------------
// it means that a function TEMPLATE can pass its arguments through to 
// another function whilst retaining the lvalue/rvalue nature of the function 
// arguments by using std::forward. This is called "perfect forwarding", 
// avoids excessive copying, and avoids the template author having to 
// write multiple overloads for lvalue and rvalue references.

template <typename T>
void iAmForwarding(T&& t) {
	iAmTargetFunction(std::forward(t));
}



template <typename T>
using u_ptr = std::unique_ptr<T>;




NS_END(rvalue_refrence_and_move_constructor )
NS_END(elloop )