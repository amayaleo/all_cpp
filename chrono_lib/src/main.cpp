#include <iostream>
#include <cstdint>
#include <chrono>
//#include <template>

using namespace std::chrono_literals;//funciona pero no esta bien

struct ClassTmp_t
{
//	Class_tmp(uint32_t x)
//	:init_variable(x)
//	{
//	};
	
uint32_t init_variable;
};

template <typename TYPE>
struct Herency_t : public ClassTmp_t
{
	//explicit Herency_t(uint32_t t)//:init_variable(t)
	//{};
uint32_t init_variable;
};



struct Class_t : public Herency_t<Class_t>{

	using clk = std::chrono::steady_clock;

	explicit Class_t(ClassTmp_t tmp)
	: init_variable(tmp.init_variable)
	{
	};

	clk::time_point last_spawn_time{clk::now()};

	std::chrono::duration<double> spawn_interval{ 5s};//toma el valor de 5 segundos y lo conviente en tiempo

	std::size_t to_be_spawned { 2 };

const uint32_t init_variable;
	
	void f_time(){
		std::cout<<"f_time()\n"<< init_variable<<std::endl;	
	}
};



struct ClassTmp
{
	static const uint32_t init_variable=10;
};


int main()
{
//[[maybe_unused]]	ClassTmp_t m_class_tmp;
//[[maybe_unused]]	m_class_tmp.init_variable=32;
	Class_t tmp(ClassTmp_t{32});

//	Class_t::f_time();
//	Class_t::init_variable;
	std::cout<<"in \n";
std::cout<< ClassTmp::init_variable << std::endl;
//[[maybe_unused]]	tmp.spawn_interval;
	tmp.f_time();
	
	std::cout<<"out\n";

  return 0;
}














