#include <iostream>
#include <cstdint>
#include <vector>


uint32_t f1(uint32_t tmp){

tmp=tmp*tmp;
return tmp;
}



uint32_t f0(uint32_t tmp){

tmp=tmp+tmp;
return tmp;
}


int main()
{


uint32_t (*p[2])(uint32_t)={f0,f1};

uint32_t result=0;

for(uint32_t i=0;i<3;i++){
result += p[i%2](i);
}

std::printf("result : %d \r\n " , result);
  return 0;

}
