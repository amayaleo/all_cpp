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

void b(){ 
    #ifdef DBG
    std::cout<<  "get()  "<< std::endl;
    #endif
  }
};


struct A : public B
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
      #ifdef DBG
      std::cout<<  "function a()  "<< std::endl;
      #endif
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
    void c()
      {
        #ifdef DBG
        std::cout<<  "c()  "<< std::endl;
        #endif
      }
  };

  C z;
  void set()
  {
    m_variable=7;   // std::cout<<  "variable : " <<m_variable <<std::endl;
  }

  void print ()
  {
     #ifdef DBG
    std::cout<<  "variable : " <<m_variable <<std::endl;
    #endif
  }

  private:
    uint32_t m_variable;
};



int main()
{
try
  {
    A a;
    a.b();

    //std::cout<<  "out  program ... "  << std::endl;
  }
catch(...)
  {
     #ifdef DBG
    std::cout<<  "error  program ... "  << std::endl;
     #endif
  }
  return 0;

}
