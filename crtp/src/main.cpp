#include <iostream>
#include <cstdint>
#include <vector>

struct P {
protected:
inline static int c {0};
};

template <typename TYPE>
struct A : P{
int static f()
	{
		static int typeID{++c};
		std::printf("typeID %d \r\n",typeID);
		return typeID;
	}
};

struct B : A <B>{

};

struct C : A <C>{

};

struct D : A <D>{

};



int main()
{
[[maybe_unused]]B b;
b.f();
[[maybe_unused]]C c;
c.f();

std::printf("result %d: \r\n ",D::f());
  return D::f();

}
