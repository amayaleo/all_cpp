#include <iostream>
#include <cstdint>
#include <vector>


struct A{

  A()

  {
      std::cout<<"A()\n";

  }
  
  template <typename TYPE>
static std::size_t function()
{
    std::vector<TYPE> type;
    type.reserve(10);
  uint32_t varm []={ 6 , 2 , 3 };
type.emplace_back();
  
  std::cout<<"entro   : " << type.size() << std::endl;
	return 1; 
}

  private:
  inline static  uint32_t variable { 0 };
};

int main()
{
try
  {
  A a;
 [[maybe_unused]] uint32_t var=4;
  a.function<uint32_t>();

  }
catch(...)
  {

  }
  return 0;

}
