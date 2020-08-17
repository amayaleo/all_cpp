#include <iostream>
#include <cstdint>
#include <vector>


uint32_t i=7;



int main()
{

uint32_t  i = 0100;

uint32_t *p;

p=&i;

    const char *const verde = "\033[0;41;36m";
        const char *const subrayado_fazul_verde = "\033[4;44;33m";
        const char *const normal = "\033[0m";

        std::printf("Mostrando %scolores %s!!!\n", verde , normal);
        std::printf("Mostrando %scolores !!!\n", verde);


std::cout << " i : " << i << std::endl; 
std::cout << " i : " << ::i << std::endl; 
std::cout << " p : " << *p << std::endl;
try
  {


  }
catch(...)
  {

  }
  return 0;

}
