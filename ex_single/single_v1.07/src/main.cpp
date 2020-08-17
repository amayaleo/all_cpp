#include <iostream>
#include <cstdint>
#include <vector>
//#include <algorithm>
//#include <memory>

//#define DBG 

struct B{
   B()
   {   
      #ifdef DBG
        std::cout<<  "  B() "<< std::endl; 
      #endif  
     };

  ~B(){   
      #ifdef DBG
        std::cout<<  " ~B() "<< std::endl;  
      #endif
    };

void b(){  std::cout<<  "get()  "<< std::endl;}
};


struct A //: public B
{
   A():z{} , m_variable { 0 } 
    { 
        #ifdef DBG
          std::cout<<  "  A() "<< std::endl; 
        #endif
    };

  ~A(){      
      #ifdef DBG
       std::cout<<  " ~A()  "<< std::endl;
      #endif
       };

void a()
  { 
    std::cout<<  "function a()  "<< std::endl;
  }
  struct  C
  {
    C(){   
          #ifdef DBG
            std::cout<<  "  C() "<< std::endl;
          #endif
       
      };
    ~C()
      {   
          #ifdef DBG
           std::cout<<  " ~C() "<< std::endl;
          #endif
      };
    void c(){std::cout<<  "c()  "<< std::endl;}
  };

  C z;
  void set()
  {
    m_variable=7;   // std::cout<<  "variable : " <<m_variable <<std::endl;
  }

  void print ()
  {
    std::cout<<  "variable : " <<m_variable <<std::endl;
  }

  private:
    uint32_t m_variable;
};



void funcion (void){
  std::cout<<  " \t call function () ... "  << std::endl;
}

int main()
{
try
  {
    void (A::*pfunc) ()=&A::print;
    std::vector <A >vect;
    auto& it = vect.emplace_back();
    auto& it2 = it;


    it.set();

    (it.*pfunc)();
    (it2.*pfunc)();



    //std::cout<<  "out  program ... "  << std::endl;
  }
catch(...)
  {
    std::cout<<  "error  program ... "  << std::endl;
  }
  return 0;

}
