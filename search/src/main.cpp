#include <iostream>
#include <cstdint>
#include <vector>
#include "ls.h"

void funcion (void){
  std::cout<<  " \t call function () ... "  << std::endl;
}

int main()
{
try
  {
RUN::Ls   search;
std::cout<<  " ************************************"  << std::endl;
search.put_ls();
std::cout<<  " ************************************"  << std::endl;
search.current_files();


    //std::cout<<  "out  program ... "  << std::endl;
  }
catch(...)
  {
    std::cout<<  "error  program ... "  << std::endl;
  }
  return 0;

}
