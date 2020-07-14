#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <memory>

struct B{
   B(){   std::cout<<  "  B() "<< std::endl; };
  ~B(){   std::cout<<  " ~B() "<< std::endl;  };
//int a{1};
void b(){  std::cout<<  "get()  "<< std::endl;}
};


struct A: public B{
   A():z{}{   std::cout<<  "  A() "<< std::endl; };
  ~A(){   std::cout<<  " ~A() "<< std::endl;  };
//int a{1};
void a()
  { 
    std::cout<<  "set()  "<< std::endl;
  }
  struct  C
  {
    C(){   std::cout<<  "  C() "<< std::endl; };
    ~C(){   std::cout<<  " ~C() "<< std::endl;  };
    void c(){std::cout<<  "c()  "<< std::endl;}
  };

  C z;
  
};


int main()
{


try
  {

//double i [] = { 4.5 , 5.6 , 6.7 };

//uint8_t h [] = { 4 ,5 , 5 ,6 , 6 ,7 };
//std::vector<A> 
//B * b ;
A * a =new A();
//b = new A();
a->z.c();
//b->get();
//a->b();

      std::cout<<  " type :  \t" << typeid(a).name()  << std::endl;
    //  std::cout<<  " type :  \t" << typeid(b).name()  << std::endl;


delete a;
//delete b;
     // std::cout<<  "size j  "  << sizeof(f) << std::endl;


    //  std::cout<<  "size j  "  << sizeof(b) << std::endl;

/*
      std::cout<<  "Struct a  "  << sizeof(a) << std::endl;
      std::cout<<  "Struct b  "  << sizeof(b) << std::endl;
      
     

      std::cout<<  "Struct a "  << sizeof(a) << std::endl;
      std::cout<<  "Struct b "  << sizeof(b) << std::endl;



      std::cout<<  " unsigned "  << sizeof(unsigned) << std::endl;
      std::cout<<  " char "  << sizeof(char) << std::endl;
      std::cout<<  " char * "  << sizeof(char *) << std::endl;
      std::cout<<  " int  "  << sizeof(int) << std::endl;
      std::cout<<  " int * "  << sizeof(int *) << std::endl;
      std::cout<<  " uint32_t "  << sizeof(uint32_t) << std::endl;
      std::cout<<  " uint32_t *"  << sizeof(uint32_t *) << std::endl;

      std::cout<<  " uint8_t "  << sizeof(uint8_t) << std::endl;
      std::cout<<  " uint8_t *"  << sizeof(uint8_t *) << std::endl;
      std::cout<<  " uint16_t "  << sizeof(uint16_t) << std::endl;
      std::cout<<  " uint16_t *"  << sizeof(uint16_t *) << std::endl;

      std::cout<<  " uint64_t "  << sizeof(uint64_t) << std::endl;
      std::cout<<  " uint64_t *"  << sizeof(uint64_t *) << std::endl;

*/

  std::cout<<  "out  program ... "  << std::endl;

  }
catch(...){
  std::cout<<  "error  program ... "  << std::endl;
}
  return 0;
}
